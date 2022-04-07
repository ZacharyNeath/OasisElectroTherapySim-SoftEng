#include "device.h"

//CONST & DEST
const double Device::MAX_POWER = 100;

Device::Device(){
    state = DeviceState::OFF;
    currentSession = nullptr;
    batteryLevel = MAX_POWER;
    connection = 0;
    batteryIn = false;
}

Device::~Device(){
    delete currentSession;
}

//END CONST & DEST

//DRIVER

//Updates status of device depending on state and session info
void Device::updateStatus(){
    //imagine this will be called once per timestep
        // timestep = 1 second/minute. Basically however often we update
    // If state is session then update battery level, timers, and counters

}

//END DRIVER

//STATE CHANGES

//To enter the on state
void Device::powerOn(){
    state = DeviceState::MENU;
}

//To enter record viewing state
void Device::recordView(){

}

//To enter session select
void Device::enterSessionSelect(){
    state = DeviceState::SESSION_SELECT;
}

//To start session
void Device::startSession(){
    // Enter session state
}

//Called at the end of the session. Finalizes session info
void Device::endSession(){
    //Add session to storage if recording is on
        // Probably doesn’t do much for now

}

//Tells device it’s testing connection
void Device::connectionTest(){
    //enter connection test state
    state = DeviceState::CONNECTION_TEST;
}

//Pauses current session
void Device::pauseSession(){
    // currently pausing just means we enter connection test state
}

//Updates whether a battery is inserted
void Device::batteryChange(){
    //flip batteryIn var
    //If battery value is critically low and user is “putting one in” imagine user has
    // swapped batteries and set battery value to max

}

//Updates device status to off
void Device::powerOff(){
    state = DeviceState::OFF;
}

//END STATE CHANGES

//DATABASE MANIP

//Returns list of records
QVector<Session*> Device::getRecords(){
    //Queries database for all/certain number of latest records
}

//Gets details for a record specified by its id
Session* Device::getRecordDetails(int){
    // gets record specified by id value from database
}

//Adds a new user defined session to the db
bool Device::createUserSession(const QString&, const QString&, const int, const bool){
    //Creates session object and tells database to add it
}

//Gets user session of specific ID
Session* Device::getUserSession(const int){
    //Gets user defined session of specific id from the database
}

//Puts current session in long term storage
bool Device::storeSession(){

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

//Increases session intensity by 1
void Device::increaseIntensity(){

}

//Decrease session intensity by 1
void Device::decreaseIntensity(){

}

//Turns on recording for current session
void Device::turnOnRecording(){
    //tells session that it will be recorded
}

//Gets remaining time in session
int Device::getSessionRemainder(){
    //calculate remaining session time and return it.
    // used to determine if session is done

}

//Returns timer from current session
QTimer* Device::getSessionTimer(){

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
