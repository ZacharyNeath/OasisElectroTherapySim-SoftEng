#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QLabel>
#include <QDateTime>
#include <QVector>
#include <QtDebug>
#include <QThread>

#include <device.h>
#include <session.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> groups;
    QVector<QLabel*> sessions;
    Device* device;
    QTimer* buttonTimer;
    int currentGroup;
    int currentSession;
    int buttonHeldTime;
    bool buttonReleased;
    bool graphFlag;

    //RECORD DISPLAY TESTING
    QVector<Session*> sessionsVect;
    Session* s1;
    Session* s2;
    Session* s3;

    //STATE UPDATES
    void powerOn(); //DONE
    void powerOff();
    void softOff();
    void enterSessionSelect();
    void startSession();
    void endSession();
    void connectionTest();

    //STORAGE QUERYING
    QVector<Session*>* getRecords();
    Session* getUserSession();

    //UI UPDATES
    void displayBattery(); //DONE
    void displayIntensity();
    void displayConnection();
    void colourGraphNumber(const int); //DONE
    void colourSession(const int); //DONE
    void colourGroup(const int); //DONE
    void displayRecords(QVector<Session*>*);
    void displaySession(Session*);
    void displayMenu(); //DONE
    void clearGraph(); //DONE
    void clearSessions(); //DONE
    void clearGroup(); //DONE
    void clearMenu(); //DONE

    //HELPER FUNCTIONS
    void connectElements();
    void buttonReset(); //DONE
    void sessionSelectInitialization(); //DONE


private slots:
    //DRIVER
    void updateStatus();

    //PRESSED
    void upPressed();
    void downPressed();
    void powerPressed();
    void confirmPressed();

    //HELD
    void upHeld();
    void downHeld();
    void powerHeld();
    void confirmHeld();

    //RELEASED
    void buttonRelease(); //DONE

    //COMBO UPDATE
    void connectionUpdate();
    void batteryChange();

};
#endif // MAINWINDOW_H
