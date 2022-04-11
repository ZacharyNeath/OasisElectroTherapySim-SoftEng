#include "device.h"

//CONST & DEST
const double Device::MAX_POWER = 100;

Device::Device(){
    longTermStorage = new LongTermStorage();
    state = DeviceState::OFF;
    currentSession = nullptr;
    batteryLevel = MAX_POWER;
    connection = 0;
    batteryIn = false;
}

Device::~Device(){
    killSession();
    delete longTermStorage;
}

//END CONST & DEST

//DRIVER

//Updates status of device depending on state and session info
void Device::updateStatus(){
    //imagine this will be called once per timestep
        // timestep = 1 second/minute. Basically however often we update
    // If state is session then update battery level, timers, and counters
    if(state == DeviceState::SOFT_OFF){
        decreaseIntensity();
    }
    else if(state == DeviceState::SESSION){
        drainBattery();
        currentSession->timeChange();
    }

}

//END DRIVER

//STATE CHANGES

//To enter the on state
void Device::powerOn(){
    state = DeviceState::MENU;
}

//To enter record viewing state
void Device::recordView(){
    state = DeviceState::RECORDS;
}

//To enter session select
void Device::enterSessionSelect(){
    state = DeviceState::SESSION_SELECT;
}

//To start session
void Device::startSession(){
    state = DeviceState::SESSION;
}

//Called at the end of the session. Finalizes session info
void Device::endSession(){
    //Add session to storage if recording is on
        // Probably doesn’t do much for now
    if(currentSession->isRecording()){
        storeSession();
    }
    state = DeviceState::SOFT_OFF;
}

//Tells device it’s testing connection
void Device::connectionTest(){
    //enter connection test state
    state = DeviceState::CONNECTION_TEST;
}

//Pauses current session
void Device::pauseSession(){
    // currently pausing just means we enter connection test state
    state = DeviceState::CONNECTION_TEST;
}

void Device::softOff(){
    state = DeviceState::SOFT_OFF;
}

//Updates device status to off
void Device::powerOff(){
    state = DeviceState::OFF;
}

//END STATE CHANGES

//DATABASE MANIP

//Returns list of records
QVector<Session*>* Device::getRecords(){
    //Queries database for all/certain number of latest records
    return longTermStorage->getRecords();
}

//Adds a new user defined session to the db
bool Device::createUserSession(const QString&, const QString&, const int, const bool){
    //Creates session object and tells database to add it
}

//Gets user session of specific ID
Session* Device::getUserSession(const int){
    //Gets user defined session of specific id from the database
    //TEMP
    return nullptr;
}

//Puts current session in long term storage
bool Device::storeSession(){
    if (longTermStorage->saveRecord(currentSession)){
        qInfo()<<"Stored Session Successfully";
        return true;
    } else {
        qInfo()<<"Failed to store Session to storage"; return false;
    }
}

//END DATABASE MANIP

//SESSION MANIP

//Creates a session
void Device::createSession(int selectedGroup, int selectedType){
    //Create session object
        //if given string is default value it is a USER DEFINED session
    QString groupString;
    QString typeString;
    int duration;
    int frequency;

    bool ces = true;

    switch(selectedGroup){
        case 0:
            groupString = "20 Minutes";
            duration = 20;
            break;
        case 1:
            groupString = "45 Minutes";
            duration = 45;
            break;
        case 2:
            groupString = "3 Hours";
            duration = 180;
            break;
        case 3:
            groupString = "User Designated";
            duration = -1;
            break;
        default:
            return;
    }

    switch(selectedType){
        case 0:
            typeString = "MET";
            frequency = 3;
            break;
        case 1:
            typeString = "Sub Delta";
            ces = false;
            frequency = 3;
            ces = false;
            break;
        case 2:
            typeString = "Delta";
            frequency = 5;
            break;
        case 3:
            typeString = "Theta";
            frequency = 8;
            break;
        case 4:
            typeString = "Alpha";
            frequency = 11;
            break;
        case 5:
            typeString = "SMR";
            frequency = 15;
            break;
        case 6:
            typeString = "Beta";
            frequency = 22;
            break;
        case 7:
            typeString = "100 Hz";
            frequency = 100;
            break;
        default:
            return;
    }

    qInfo("\nCreating session:");
    qInfo("Group:     %s", qUtf8Printable(groupString));
    qInfo("Type:      %s", qUtf8Printable(typeString));
    qInfo("Duration:  %d minutes", duration);
    qInfo("Frequency: %dHz", frequency);
    qInfo("CES:       %s\n", ces?"Short-Pulse":"50% Duty Cycle");

    currentSession = new Session(groupString, typeString, duration, frequency, ces);
}

void Device::acceptUserSession(Session* userSession){
    currentSession = userSession;
}

//Increases session intensity by 1
void Device::increaseIntensity(){
    int currentIntensity = currentSession->getIntensity();
    if(currentIntensity<8){
        currentSession->setIntensity(currentIntensity+1);
    }
}

//Decrease session intensity by 1
void Device::decreaseIntensity(){
    int currentIntensity = currentSession->getIntensity();
    if(currentIntensity>0){
        currentSession->setIntensity(currentIntensity-1);
    }
}

//Turns on recording for current session
void Device::turnOnRecording(){
    //tells session that it will be recorded
    currentSession->setRecording(true);
}

//Gets remaining time in session
int Device::getSessionRemainder(){
    //calculate remaining session time and return it.
    // used to determine if session is done
    int remainder = currentSession->getDuration() - currentSession->timeElapsed();
    return remainder;
}

//Returns timer from current session
QTimer* Device::getSessionTimer(){
    return currentSession->getTimer();
}

//Returns intensity from session
int Device::getIntensity(){
    return currentSession->getIntensity();
}

//For when the device powers off unexpectedly
void Device::killSession(){
    if(currentSession!=nullptr){
        delete currentSession;
        currentSession = nullptr;
    }
}

//END SESSION MANIP

//GETTERS

//Gets current state of device
DeviceState Device::getState(){
    return state;
}

//Gets current battery level
double Device::getBatteryLevel(){
    return batteryLevel;
}

//Gets current connection status
int Device::getConnectionLevel(){
    return connection;
}

//Gets battery insertion status
bool Device::isBatteryIn(){
    return batteryIn;
}

bool Device::batteryCritical(){
    if(batteryLevel < MAX_POWER/8){
        return true;
    }

    return false;
}

//SETTERS

void Device::setConnection(const int c){
    connection = c;
}

void Device::setBattery(const bool b){
    //If battery is critical and it's being reinserted imagine the user has changed battery
    if(batteryIn == false && b == true && batteryCritical()){
        batteryLevel = MAX_POWER;
    }
    batteryIn = b;
}

//END SETTERS

//HELPERS

//Calculates and applies battery drain
void Device::drainBattery(){
    double drain = (0.15 * currentSession->getIntensity()) * ((0.01 * currentSession->getFrequency()) + (connection));
    batteryLevel = batteryLevel - drain;
}

//END HELPERS
