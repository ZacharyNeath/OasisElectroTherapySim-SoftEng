#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>

class Session : public QObject
{
    Q_OBJECT
public:
    //CONST & DEST
    Session(const QString&, const QString&, const int, const int, const bool);
    Session(const QString&, const QString&, const int, const int, const bool, const QDateTime);
    ~Session();

    //UTILITY
    void timeChange();
    int timeLeft();

    //GETTERS
    QString getGroup();
    QString getType();
    QTimer* getTimer();
    QString getTimeString();
    int getDuration();
    int getFrequency();
    int timeElapsed();
    int getIntensity();
    bool getCES();
    bool isRecording();

    //SETTERS
    void setIntensity(int);
    void setRecording(const bool);

private:
    QTimer* timer;
    QDateTime dateTime;
    QString group;
    QString type;
    int frequency;
    int duration;
    int currentDuration;
    int intensity;
    bool cesMode; // true = short-pulse, false = 50% duty cycle
    bool record;

};

#endif // SESSION_H
