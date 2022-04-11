#ifndef LONGTERMSTORAGE_H
#define LONGTERMSTORAGE_H

#include <QObject>
#include <QString>
#include <iostream>
#include <QVector>
#include <QFile>
#include <QJsonArray>
#include <QtDebug>
#include <QJsonObject>
#include <QJsonDocument>

#include <session.h>
using namespace std;

class LongTermStorage : public QObject
{
    Q_OBJECT
public:
    //CTOR & DTOR
    LongTermStorage();
    ~LongTermStorage();

    //GETTERS
    QVector<Session*>* getRecords();
    QVector<Session*>* getUserSession(const int);


private:
    //FILE
    const QString RECORD_FILE = "../3004-Project/Data/records.json";
    const QString USER_SESSION_FILE = "../3004-Project/Data/records.json";

    //STORAGE VECTORS
    QVector<Session*> records;
    QVector<Session*> userSessions;

    //LOAD & SAVE FROM FILE
    bool loadRecords();
    bool saveRecord(Session*);
    bool loadUserSessions();
    bool saveUserSession(Session*);

    //HELPERS
    Session* createSession(const QString& groupString, const QString& typeString, const int duration, const int frequency, const bool ces, const QString);

};


#endif // LONGTERMSTORAGE_H
