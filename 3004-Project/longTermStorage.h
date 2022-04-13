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

class LongTermStorage : public QObject
{
    Q_OBJECT
public:
    //CTOR & DTOR
    LongTermStorage();
    ~LongTermStorage();

    //GETTERS
    QVector<Session*>* getRecords();
    Session* getUserSession(const int);

    //LOAD & SAVE FROM FILE
    bool loadRecords();
    bool saveRecord(Session*);
    bool loadUserSessions();
    bool saveUserSession(Session*);

private:
    //FILE
    const static QString RECORD_FILE;
    const static QString USER_SESSION_FILE;

    //STORAGE VECTORS
    QVector<Session*> records;
    QVector<Session*> userSessions;


    //HELPERS
    Session* createSession(const QString&, const QString&, const int, const int, const bool, const QString, const int);

};


#endif // LONGTERMSTORAGE_H
