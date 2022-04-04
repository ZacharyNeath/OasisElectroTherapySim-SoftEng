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
void Device::createSession(const QString&, const QString&){
    //Create session object
        //if given string is default value it is a USER DEFINED session
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
