#include "session.h"

//CONST & DEST

Session::Session(const QString& group, const QString& type, const int duration, const int frequency, const bool ces){
    this->group = group;
    this->type = type;
    this->duration = duration;
    this->frequency = frequency;
    this->cesMode = ces;

    this->currentDuration = 0;
    this->intensity = 0;
    this->record = false;
    dateTime = QDateTime::currentDateTime();

    //For more details on how it repeats
    //https://doc.qt.io/qt-5/qtimer.html#details
    timer = new QTimer(this);

}

Session::Session(const QString& group, const QString& type, const int duration, const int frequency, const bool ces, const QDateTime dt){
    this->group = group;
    this->type = type;
    this->duration = duration;
    this->frequency = frequency;
    this->cesMode = ces;
    this->dateTime = dt; //dateTime = QDateTime::currentDateTime();

    this->currentDuration = 0;
    this->intensity = 0;
    this->record = false;

    //For more details on how it repeats
    //https://doc.qt.io/qt-5/qtimer.html#details
    timer = new QTimer(this);

}

Session::~Session(){
    delete timer;
}

//END CONST & DEST

//UTILITY

//Updates the current duration
void Session::timeChange(){
    ++currentDuration;
}

//Returns how much time is left in the session
int Session::timeLeft(){
    return (duration - currentDuration);
}

//END UTILITY

//GETTERS

//Returns group
QString Session::getGroup(){
    return group;
}

//Returns type
QString Session::getType(){
    return type;
}

//Returns timer
QTimer* Session::getTimer(){
    return timer;
}

//Returns date and time of object
QString Session::getTimeString(){
    return dateTime.toString();
}

//Returns duration
int Session::getDuration(){
    return duration;
}

//Returns frequency
int Session::getFrequency(){
    return frequency;
}

//Returns current duration
int Session::timeElapsed(){
    return currentDuration;
}

//Returns intensity
int Session::getIntensity(){
    return intensity;
}

//Returns CES mode
bool Session::getCES(){
    return cesMode;
}

//Returns record flag
bool Session::isRecording(){
    return record;
}

//END GETTERS

//SETTERS

//Sets intensity
void Session::setIntensity(int newIntensity){
    intensity = newIntensity;
}

//Sets recording flag
void Session::setRecording(const bool r){
    record = r;
}

//END SETTERS
