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

    //STATE UPDATES
    void powerOn();
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
    void displayBattery();
    void displayIntensity();
    void displayConnection();
    void colourGraphNumber(const int);
    void colourSession(const int);
    void colourGroup(const int);
    void displayRecords(QVector<Session*>*);
    void displaySession(Session*);
    void displayMenu();
    void clearGraph();
    void clearSessions();
    void clearGroup();
    void clearMenu();

    //HELPER FUNCTIONS
    void connectElements();
    void buttonReset();
    void sessionSelectInitialization();


private slots:
    //DRIVER
    void updateStatus();

    //PRESSED
    void upPressed();
    void downPressed();
    void powerPressed();
    void confirmPressed();

    //HELD
    void powerHeld();
    void confirmHeld();

    //RELEASED
    void buttonRelease();

    //COMBO UPDATE
    void connectionUpdate();
    void batteryChange();

};
#endif // MAINWINDOW_H
