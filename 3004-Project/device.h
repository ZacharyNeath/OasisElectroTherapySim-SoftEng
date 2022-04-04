#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QTimer>
#include <session.h>

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
    void powerOn(); //DONE
    void recordView();
    void enterSessionSelect(); //DONE
    void connectionTest();
    void startSession();
    void endSession();
    void pauseSession();
    void batteryChange();
    void powerOff(); //DONE

    //DATABASE MANIP
    QVector<Session*> getRecords();
    Session* getRecordDetails(int);
    bool createUserSession(const QString&, const QString&, const int, const bool);
    Session* getUserSession(const int);
    bool storeSession();

    //SESSION MANIP
    void createSession(const QString&, const QString&);
    void increaseIntensity();
    void decreaseIntensity();
    void turnOnRecording();
    int getSessionRemainder();
    QTimer* getSessionTimer();

    //GETTERS //DONE
    DeviceState getState();
    double getBatteryLevel();
    int getConnectionLevel();
    bool isBatteryIn();

private:
    //STATIC
    static const double MAX_POWER;

    //ENUM
    DeviceState state;

    //MAIN STUFF
    Session* currentSession;
    double batteryLevel;
    int connection; //0 = poor, 1 = okay, 2 = excellent
    bool batteryIn;

};

#endif // DEVICE_H
