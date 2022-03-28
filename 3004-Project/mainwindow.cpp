#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> powerButton, SIGNAL(released()), this, SLOT(powerButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::powerButton() {
    if (!poweredOn) {
        ui->powerIndicator->setStyleSheet("color: rgb(138, 226, 52)");
        ui->display->setStyleSheet("background-color: rgb(255, 255, 255);");
        poweredOn = true;
    }
    else {
        ui -> powerIndicator->setStyleSheet("color: rgb(85, 87, 83);");
        ui->display->setStyleSheet("background-color: rgb(85, 87, 83);");
        poweredOn = false;
    }
}
