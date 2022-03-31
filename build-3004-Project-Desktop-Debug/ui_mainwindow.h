/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *powerButton;
    QPushButton *intUp;
    QPushButton *intDown;
    QPushButton *confirm;
    QLabel *intensity;
    QLabel *twentyMin;
    QLabel *fortyFiveMin;
    QLabel *threeHour;
    QLabel *userDesig;
    QLabel *cesOut;
    QLabel *audioIn;
    QLabel *left;
    QLabel *right;
    QLabel *one;
    QLabel *two;
    QLabel *three;
    QLabel *four;
    QLabel *five;
    QLabel *six;
    QLabel *seven;
    QLabel *eight;
    QLabel *tdcs;
    QLabel *shortPulse;
    QLabel *dutyCycle;
    QLabel *tdcsPlusTwo;
    QLabel *tdcsTwo;
    QLabel *tdcsOne;
    QLabel *tdcsThreeQuarters;
    QLabel *tdcsHalf;
    QLabel *tdcsQuarter;
    QLabel *tdcsPlusOne;
    QLabel *tdcsOneAndHalf;
    QLabel *met;
    QLabel *subDelta;
    QLabel *delta;
    QLabel *theta;
    QLabel *alpha;
    QLabel *smr;
    QLabel *beta;
    QLabel *hundredHz;
    QLabel *powerIndicator;
    QFrame *line;
    QLabel *electrodesConnected;
    QLabel *batteryInserted;
    QComboBox *electrodesOn;
    QComboBox *batteryIn;
    QListWidget *display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(783, 461);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(680, 280, 80, 25));
        powerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        intUp = new QPushButton(centralwidget);
        intUp->setObjectName(QString::fromUtf8("intUp"));
        intUp->setGeometry(QRect(550, 260, 80, 25));
        intUp->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        intDown = new QPushButton(centralwidget);
        intDown->setObjectName(QString::fromUtf8("intDown"));
        intDown->setGeometry(QRect(550, 290, 80, 25));
        intDown->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        confirm = new QPushButton(centralwidget);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(50, 280, 80, 25));
        confirm->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        intensity = new QLabel(centralwidget);
        intensity->setObjectName(QString::fromUtf8("intensity"));
        intensity->setGeometry(QRect(570, 220, 41, 41));
        QFont font;
        font.setPointSize(20);
        intensity->setFont(font);
        intensity->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        twentyMin = new QLabel(centralwidget);
        twentyMin->setObjectName(QString::fromUtf8("twentyMin"));
        twentyMin->setGeometry(QRect(133, 10, 71, 20));
        twentyMin->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        fortyFiveMin = new QLabel(centralwidget);
        fortyFiveMin->setObjectName(QString::fromUtf8("fortyFiveMin"));
        fortyFiveMin->setGeometry(QRect(220, 10, 61, 17));
        fortyFiveMin->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        threeHour = new QLabel(centralwidget);
        threeHour->setObjectName(QString::fromUtf8("threeHour"));
        threeHour->setGeometry(QRect(310, 10, 54, 17));
        threeHour->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        userDesig = new QLabel(centralwidget);
        userDesig->setObjectName(QString::fromUtf8("userDesig"));
        userDesig->setGeometry(QRect(390, 10, 101, 17));
        userDesig->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        cesOut = new QLabel(centralwidget);
        cesOut->setObjectName(QString::fromUtf8("cesOut"));
        cesOut->setGeometry(QRect(10, 250, 54, 17));
        cesOut->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        audioIn = new QLabel(centralwidget);
        audioIn->setObjectName(QString::fromUtf8("audioIn"));
        audioIn->setGeometry(QRect(10, 0, 54, 17));
        audioIn->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        left = new QLabel(centralwidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(570, 30, 16, 17));
        left->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        right = new QLabel(centralwidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(660, 30, 16, 17));
        right->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        one = new QLabel(centralwidget);
        one->setObjectName(QString::fromUtf8("one"));
        one->setGeometry(QRect(200, 290, 21, 17));
        one->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        two = new QLabel(centralwidget);
        two->setObjectName(QString::fromUtf8("two"));
        two->setGeometry(QRect(200, 270, 21, 17));
        two->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        three = new QLabel(centralwidget);
        three->setObjectName(QString::fromUtf8("three"));
        three->setGeometry(QRect(200, 250, 21, 17));
        three->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        four = new QLabel(centralwidget);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(200, 230, 21, 17));
        four->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        five = new QLabel(centralwidget);
        five->setObjectName(QString::fromUtf8("five"));
        five->setGeometry(QRect(200, 210, 21, 17));
        five->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        six = new QLabel(centralwidget);
        six->setObjectName(QString::fromUtf8("six"));
        six->setGeometry(QRect(200, 190, 21, 17));
        six->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        seven = new QLabel(centralwidget);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setGeometry(QRect(200, 170, 21, 17));
        seven->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        eight = new QLabel(centralwidget);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setGeometry(QRect(200, 150, 21, 17));
        eight->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcs = new QLabel(centralwidget);
        tdcs->setObjectName(QString::fromUtf8("tdcs"));
        tdcs->setGeometry(QRect(290, 130, 31, 17));
        tdcs->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        shortPulse = new QLabel(centralwidget);
        shortPulse->setObjectName(QString::fromUtf8("shortPulse"));
        shortPulse->setGeometry(QRect(540, 10, 71, 17));
        shortPulse->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        dutyCycle = new QLabel(centralwidget);
        dutyCycle->setObjectName(QString::fromUtf8("dutyCycle"));
        dutyCycle->setGeometry(QRect(620, 10, 91, 17));
        dutyCycle->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsPlusTwo = new QLabel(centralwidget);
        tdcsPlusTwo->setObjectName(QString::fromUtf8("tdcsPlusTwo"));
        tdcsPlusTwo->setGeometry(QRect(290, 150, 21, 17));
        tdcsPlusTwo->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsTwo = new QLabel(centralwidget);
        tdcsTwo->setObjectName(QString::fromUtf8("tdcsTwo"));
        tdcsTwo->setGeometry(QRect(290, 190, 31, 17));
        tdcsTwo->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsOne = new QLabel(centralwidget);
        tdcsOne->setObjectName(QString::fromUtf8("tdcsOne"));
        tdcsOne->setGeometry(QRect(290, 230, 31, 17));
        tdcsOne->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsThreeQuarters = new QLabel(centralwidget);
        tdcsThreeQuarters->setObjectName(QString::fromUtf8("tdcsThreeQuarters"));
        tdcsThreeQuarters->setGeometry(QRect(290, 250, 31, 17));
        tdcsThreeQuarters->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsHalf = new QLabel(centralwidget);
        tdcsHalf->setObjectName(QString::fromUtf8("tdcsHalf"));
        tdcsHalf->setGeometry(QRect(290, 270, 31, 17));
        tdcsHalf->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsQuarter = new QLabel(centralwidget);
        tdcsQuarter->setObjectName(QString::fromUtf8("tdcsQuarter"));
        tdcsQuarter->setGeometry(QRect(290, 290, 31, 17));
        tdcsQuarter->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsPlusOne = new QLabel(centralwidget);
        tdcsPlusOne->setObjectName(QString::fromUtf8("tdcsPlusOne"));
        tdcsPlusOne->setGeometry(QRect(290, 170, 21, 17));
        tdcsPlusOne->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        tdcsOneAndHalf = new QLabel(centralwidget);
        tdcsOneAndHalf->setObjectName(QString::fromUtf8("tdcsOneAndHalf"));
        tdcsOneAndHalf->setGeometry(QRect(290, 210, 31, 17));
        tdcsOneAndHalf->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        met = new QLabel(centralwidget);
        met->setObjectName(QString::fromUtf8("met"));
        met->setGeometry(QRect(120, 40, 31, 17));
        met->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        subDelta = new QLabel(centralwidget);
        subDelta->setObjectName(QString::fromUtf8("subDelta"));
        subDelta->setGeometry(QRect(160, 40, 61, 17));
        subDelta->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        delta = new QLabel(centralwidget);
        delta->setObjectName(QString::fromUtf8("delta"));
        delta->setGeometry(QRect(230, 40, 31, 17));
        delta->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        theta = new QLabel(centralwidget);
        theta->setObjectName(QString::fromUtf8("theta"));
        theta->setGeometry(QRect(280, 40, 41, 17));
        theta->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        alpha = new QLabel(centralwidget);
        alpha->setObjectName(QString::fromUtf8("alpha"));
        alpha->setGeometry(QRect(330, 40, 41, 17));
        alpha->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        smr = new QLabel(centralwidget);
        smr->setObjectName(QString::fromUtf8("smr"));
        smr->setGeometry(QRect(380, 40, 41, 17));
        smr->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        beta = new QLabel(centralwidget);
        beta->setObjectName(QString::fromUtf8("beta"));
        beta->setGeometry(QRect(430, 40, 41, 17));
        beta->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        hundredHz = new QLabel(centralwidget);
        hundredHz->setObjectName(QString::fromUtf8("hundredHz"));
        hundredHz->setGeometry(QRect(480, 40, 41, 17));
        hundredHz->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83);"));
        powerIndicator = new QLabel(centralwidget);
        powerIndicator->setObjectName(QString::fromUtf8("powerIndicator"));
        powerIndicator->setGeometry(QRect(710, 250, 21, 17));
        QFont font1;
        font1.setPointSize(50);
        font1.setBold(true);
        font1.setWeight(75);
        powerIndicator->setFont(font1);
        powerIndicator->setStyleSheet(QString::fromUtf8("color: rgb(85, 87, 83)"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 350, 821, 16));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        line->setFont(font2);
        line->setAutoFillBackground(false);
        line->setStyleSheet(QString::fromUtf8(""));
        line->setLineWidth(5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        electrodesConnected = new QLabel(centralwidget);
        electrodesConnected->setObjectName(QString::fromUtf8("electrodesConnected"));
        electrodesConnected->setGeometry(QRect(10, 380, 131, 17));
        electrodesConnected->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        batteryInserted = new QLabel(centralwidget);
        batteryInserted->setObjectName(QString::fromUtf8("batteryInserted"));
        batteryInserted->setGeometry(QRect(270, 380, 101, 17));
        batteryInserted->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        electrodesOn = new QComboBox(centralwidget);
        electrodesOn->addItem(QString());
        electrodesOn->addItem(QString());
        electrodesOn->addItem(QString());
        electrodesOn->setObjectName(QString::fromUtf8("electrodesOn"));
        electrodesOn->setGeometry(QRect(140, 380, 81, 25));
        electrodesOn->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        batteryIn = new QComboBox(centralwidget);
        batteryIn->addItem(QString());
        batteryIn->addItem(QString());
        batteryIn->setObjectName(QString::fromUtf8("batteryIn"));
        batteryIn->setGeometry(QRect(370, 380, 72, 25));
        batteryIn->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        display = new QListWidget(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(370, 90, 401, 121));
        display->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 783, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        powerButton->setText(QApplication::translate("MainWindow", "Power", nullptr));
        intUp->setText(QApplication::translate("MainWindow", "UP", nullptr));
        intDown->setText(QApplication::translate("MainWindow", "DOWN", nullptr));
        confirm->setText(QApplication::translate("MainWindow", "Confirm", nullptr));
        intensity->setText(QApplication::translate("MainWindow", "INT", nullptr));
        twentyMin->setText(QApplication::translate("MainWindow", "20 Minutes", nullptr));
        fortyFiveMin->setText(QApplication::translate("MainWindow", "45 Minutes", nullptr));
        threeHour->setText(QApplication::translate("MainWindow", "3 Hours", nullptr));
        userDesig->setText(QApplication::translate("MainWindow", "User Designated", nullptr));
        cesOut->setText(QApplication::translate("MainWindow", "CES Out.", nullptr));
        audioIn->setText(QApplication::translate("MainWindow", "Audio In.", nullptr));
        left->setText(QApplication::translate("MainWindow", "L", nullptr));
        right->setText(QApplication::translate("MainWindow", "R", nullptr));
        one->setText(QApplication::translate("MainWindow", "|1|", nullptr));
        two->setText(QApplication::translate("MainWindow", "|2|", nullptr));
        three->setText(QApplication::translate("MainWindow", "|3|", nullptr));
        four->setText(QApplication::translate("MainWindow", "|4|", nullptr));
        five->setText(QApplication::translate("MainWindow", "|5|", nullptr));
        six->setText(QApplication::translate("MainWindow", "|6|", nullptr));
        seven->setText(QApplication::translate("MainWindow", "|7|", nullptr));
        eight->setText(QApplication::translate("MainWindow", "|8|", nullptr));
        tdcs->setText(QApplication::translate("MainWindow", "tDCS", nullptr));
        shortPulse->setText(QApplication::translate("MainWindow", "Short-Pulse", nullptr));
        dutyCycle->setText(QApplication::translate("MainWindow", "50% Duty Cycle", nullptr));
        tdcsPlusTwo->setText(QApplication::translate("MainWindow", "+2", nullptr));
        tdcsTwo->setText(QApplication::translate("MainWindow", "2.00", nullptr));
        tdcsOne->setText(QApplication::translate("MainWindow", "1.00", nullptr));
        tdcsThreeQuarters->setText(QApplication::translate("MainWindow", "0.75", nullptr));
        tdcsHalf->setText(QApplication::translate("MainWindow", "0.50", nullptr));
        tdcsQuarter->setText(QApplication::translate("MainWindow", "0.25", nullptr));
        tdcsPlusOne->setText(QApplication::translate("MainWindow", "+1", nullptr));
        tdcsOneAndHalf->setText(QApplication::translate("MainWindow", "1.50", nullptr));
        met->setText(QApplication::translate("MainWindow", "MET", nullptr));
        subDelta->setText(QApplication::translate("MainWindow", "Sub-Delta", nullptr));
        delta->setText(QApplication::translate("MainWindow", "Delta", nullptr));
        theta->setText(QApplication::translate("MainWindow", "Theta", nullptr));
        alpha->setText(QApplication::translate("MainWindow", "Alpha", nullptr));
        smr->setText(QApplication::translate("MainWindow", "SMR", nullptr));
        beta->setText(QApplication::translate("MainWindow", "Beta", nullptr));
        hundredHz->setText(QApplication::translate("MainWindow", "100 Hz", nullptr));
        powerIndicator->setText(QApplication::translate("MainWindow", "-", nullptr));
        electrodesConnected->setText(QApplication::translate("MainWindow", "Electrode Connection:", nullptr));
        batteryInserted->setText(QApplication::translate("MainWindow", "Battery Inserted:", nullptr));
        electrodesOn->setItemText(0, QApplication::translate("MainWindow", "Excellent", nullptr));
        electrodesOn->setItemText(1, QApplication::translate("MainWindow", "Okay", nullptr));
        electrodesOn->setItemText(2, QApplication::translate("MainWindow", "Poor", nullptr));

        batteryIn->setItemText(0, QApplication::translate("MainWindow", "True", nullptr));
        batteryIn->setItemText(1, QApplication::translate("MainWindow", "False", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
