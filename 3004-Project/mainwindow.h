#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <QtDebug>

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
    Device* device;
    QTimer* buttonTimer;
    int buttonHeldTime;
    bool buttonPressed;
    bool buttonReleased;

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
    Session* getRecordDetails();
    Session* getUserSession();

    //UI UPDATES
    void displayBattery();
    void displayIntensity();
    void colourGraphNumber(const int);
    void displayRecords(QVector<Session*>*);
    void displaySession(Session*);
    void displayMenu();
    void clearGraph();
    void clearMenu();
    void clearUI();

    //HELPER FUNCTIONS
    void connectButtons();
    void buttonReset();


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
    void buttonRelease();

    //COMBO UPDATE
    void connectionUpdate();
    void batteryChange();

};
#endif // MAINWINDOW_H
