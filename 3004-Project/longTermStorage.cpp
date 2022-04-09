#include "longTermStorage.h"

//CTOR & DTOR
const QString LongTermStorage::RECORD_FILE = "";
const QString LongTermStorage::USER_SESSION_FILE = "";

LongTermStorage::LongTermStorage(){
    qInfo() << "    --LongTermStorage Ctor";
}

LongTermStorage::~LongTermStorage(){
    qInfo() << "    --LongTermStorage Ctor";
}

//END CTOR & DTOR


// LOAD/SAVE FROM FILE

//Read record file and fill record collection
bool LongTermStorage::loadRecords(){

    return false;
}

//Add given session record to record file
bool LongTermStorage::saveRecord(Session* s){

    return false;
}

//Read record file and fill record collection
bool LongTermStorage::loadUserSessions(){

    return false;
}

//Add given session record to record file
bool LongTermStorage::saveUserSession(Session* s){

    return false;
}

//END LOAD/SAVE


//GETTERS

//Return pointer to record colleciton
QVector<Session*>* LongTermStorage::getRecords(){

}

//Return User session with given id
QVector<Session*>* LongTermStorage::getRecords(const int id){

}

//END GETTERS


//HELPERS
///Create and return new session object
Session* LongTermStorage::createSession(const QString& groupString, const QString& typeString, const int duration, const int frequency, const bool ces){
    return new Session(groupString, typeString, duration, frequency, ces);
}
