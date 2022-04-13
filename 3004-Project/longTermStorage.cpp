#include "longTermStorage.h"

const QString LongTermStorage::RECORD_FILE = "../3004-Project/Data/records.json";
const QString LongTermStorage::USER_SESSION_FILE = "../3004-Project/Data/records.json";

//CTOR & DTOR

LongTermStorage::LongTermStorage(){
    loadRecords();

    //TESTING FOR SAVING RECORD

    //when LTS is contructed adds a test session to the json file right away
    //feel free to add more/change it to test
    //also let me know if it actually saves to a file when session is complete

    //Session* s = new Session("20 Minutes","100Hz",20,100,true);  //uncomment these lines
    //saveRecord(s);                                               //

    qInfo()<< "    --LongTermStorage Ctor";
}

LongTermStorage::~LongTermStorage(){
    qInfo()<< "    --LongTermStorage dtor";
    for(int i = 0; i<records.count(); i++){
        delete records[i];
    }
    for(int i = 0; i<userSessions.count(); i++){
        delete userSessions[i];
    }
}

//END CTOR & DTOR


// LOAD/SAVE FROM FILE

//Read record file and fill record collection
bool LongTermStorage::loadRecords(){
    //Get JsonDocument from file
    QFile file(RECORD_FILE);
    QString value;
    if( file.open( QFile::ReadOnly )){
        qInfo() << "Info: ------- successfully opened file: "<<RECORD_FILE;
        value = file.readAll();
        file.close();
    } else {
        qInfo() << "Error: ------- reading file: "<<RECORD_FILE;
        return false;
    }
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8());

    //Add inner objects to collection
    QJsonArray content = document.array();

    for( auto v : content){
        //Create QJsonObject from array entry
        QJsonObject o = v.toObject();
        Session* s = createSession(o["Group"].toString(), o["Type"].toString(), o["Time"].toInt(), o["Frequency"].toInt(), o["CES Mode"].toBool(), o["Date"].toString(), o["Duration"].toInt());
        records.push_back(s);
        //qInfo()<< s->getGroup() << " " << s->getType() << " " << s->getDuration() << " " << s->getFrequency()<< " " << s->getCES()<< " ";
    }

    return true;
}

//Add given session record to record file
bool LongTermStorage::saveRecord(Session* s){
    //Push record to collection
    records.push_back(new Session(*s));

    //Create QJsonArray out of collection
    QJsonArray content;
    for(auto v : records){
        //Create JsonObject out of each session record and push to array
        QJsonObject o;
        o.insert("CES Mode",v->getCES());
        o.insert("Date",v->getTimeString());
        o.insert("Duration",v->timeElapsed());
        o.insert("Time", v->getDuration());
        o.insert("Frequency",v->getFrequency());
        o.insert("Group",v->getGroup());
        o.insert("Type",v->getType());
        content.push_back(o);
    }

    //Write JsonObject to file
    QJsonDocument document;
    document.setArray(content);

    QFile file(RECORD_FILE);
    if( file.open(QFile::WriteOnly) ){
        qInfo() << "Info: ------- successfully opened file: "<<RECORD_FILE;
        file.write(document.toJson());
        file.close();
    }else{
        qInfo() << "Error: ------- writing to file: "<<RECORD_FILE;
        return false;
    }

    return true;
}

//Read record file and fill record collection
bool LongTermStorage::loadUserSessions(){

    return true;
}

//Add given session record to record file
bool LongTermStorage::saveUserSession(Session* s){

    return false;
}

//END LOAD/SAVE


//GETTERS

//Return pointer to record colleciton
QVector<Session*>* LongTermStorage::getRecords(){
    return &records;
}

//Return User session with given id
QVector<Session*>* LongTermStorage::getUserSession(const int id){

    return nullptr;
}

//END GETTERS


//HELPERS
///Create and return new session object
Session* LongTermStorage::createSession(const QString& groupString, const QString& typeString, const int duration, const int frequency, const bool ces, const QString date, const int timeElapsed){
    QDateTime dt = QDateTime::fromString(date,"ddd MMM dd HH:mm:ss yyyy");
    return new Session(groupString, typeString, duration, frequency, ces, dt, timeElapsed);
}
