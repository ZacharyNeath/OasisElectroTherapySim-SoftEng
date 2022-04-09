#ifndef LONGTERMSTORAGE_H
#define LONGTERMSTORAGE_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QFile>
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
    QVector<Session*>* getUserSessions();


private:
    //FILE
    const QString RECORD_FILE;
    const QString USER_SESSION_FILE;

    //STORAGE VECTORS
    QVector<Session*> records;
    QVector<Session*> userSessions;

    //LOAD & SAVE FROM FILE
    bool loadRecords();
    bool saveRecord(Session*);
    bool loadUserSessions();
    bool saveUserSession(Session*);

    //HELPERS
    Session* createSession(QString groupString, QString typeString, int duration, int frequency, QString ces);

};


#endif // LONGTERMSTORAGE_H
