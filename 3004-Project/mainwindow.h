#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>

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
//Follow below for how we'll navigate session info
//    //Imagine these vars are class vars
//    int currentGroup = 0;
//    QLabel** groups = new QLabel*[4];

//    //Imagine this is in the function to navigate
//    groups[0] = ui->twentyMinLabel;
//    //...

//    currentGroup+=1;
//    groups[currentGroup%4]->setCurrentStyleSheet("Set colour");
    Ui::MainWindow *ui;
    Device* device;
    QTimer* buttonTimer;
    int buttonHeldTime;
    bool buttonReleased;

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
    Session* getRecordDetails();
    Session* getUserSession();

    //UI UPDATES
    void displayBattery(); //DONE
    void displayIntensity();
    void colourGraphNumber(const int); //DONE
    void displayRecords(QVector<Session*>*);
    void displaySession(Session*);
    void displayMenu(); //DONE
    void clearGraph(); //DONE
    void clearMenu(); //DONE
    void clearUI();

    //HELPER FUNCTIONS
    void connectElements();
    void buttonReset(); //DONE


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
