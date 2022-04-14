#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QTimer>
#include <session.h>
#include <longTermStorage.h>

enum DeviceState {OFF, MENU, RECORDS, SESSION_SELECT, CONNECTION_TEST, SESSION, SOFT_OFF};

class Device : public QObject
{
    Q_OBJECT
public:
    //CONST & DEST
    Device();
    ~Device();

    //DRIVER
    void updateStatus();

    //STATE CHANGES
    void powerOn();
    void recordView();
    void enterSessionSelect();
    void connectionTest();
    void startSession();
    void endSession();
    void pauseSession();
    void softOff();
    void powerOff();

    //DATABASE MANIP
    QVector<Session*>* getRecords();
    bool createUserSession(const QString&, const int, const int, const bool);
    Session* getUserSession(const int);
    bool storeSession();

    //SESSION MANIP
    void createSession(const int, const int);
    void acceptUserSession(Session*);
    void increaseIntensity();
    void decreaseIntensity();
    void turnOnRecording();
    int getSessionRemainder();
    QTimer* getSessionTimer();
    int getIntensity();
    void killSession();

    //GETTERS
    DeviceState getState();
    double getBatteryLevel();
    int getConnectionLevel();
    bool isBatteryIn();
    bool batteryCritical();

    //SETTERS
    void setConnection(const int);
    void setBattery(const bool);

private:
    //STATIC
    static const double MAX_POWER;

    //DATABASE
    LongTermStorage* longTermStorage;

    //ENUM
    DeviceState state;

    //MAIN STUFF
    Session* currentSession;
    double batteryLevel;
    int connection; //0 = poor, 1 = okay, 2 = excellent
    bool batteryIn;

    //HELPERS
    void drainBattery();

};

#endif // DEVICE_H
