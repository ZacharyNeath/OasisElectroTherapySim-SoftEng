#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectButtons() {
    connect(ui -> powerButton, SIGNAL(released()), this, SLOT(powerButton()));
    connect(ui -> intUp, SIGNAL(released()), this, SLOT(up()));
    connect(ui -> intDown, SIGNAL(released()), this, SLOT(down()));
    connect(ui -> confirm, SIGNAL(released()), this, SLOT(select()));
}

void MainWindow::powerButton() {
    if (!poweredOn) {
        ui->powerIndicator->setStyleSheet("color: rgb(138, 226, 52)");
        ui->display->setStyleSheet("background-color: rgb(255, 255, 255);");

        //Populates the display options
        QListWidgetItem *session = new QListWidgetItem;
        session->setText("Select a session");
        ui->display->insertItem(0, session);

        QListWidgetItem *records = new QListWidgetItem;
        records->setText("View records");
        ui->display->insertItem(1, records);

        ui->display->setCurrentItem(session);

        poweredOn = true;
        state = "menu";
    }
    else {
        ui -> powerIndicator->setStyleSheet("color: rgb(85, 87, 83);");
        ui->display->setStyleSheet("background-color: rgb(85, 87, 83);");

        ui->display->clear();

        poweredOn = false;
        state = "off";
    }
}

void MainWindow::up() {
    if (state == "menu" && ui->display->currentRow() != 0) {
        ui->display->setCurrentRow(ui->display->currentRow() - 1);
    }
}

void MainWindow::down() {
    if (state == "menu" && ui->display->currentRow() != ui->display->count() - 1) {
        ui->display->setCurrentRow(ui->display->currentRow() + 1);
    }
}

void MainWindow::select() {
    if (state == "menu") {
        if (ui->display->currentRow() == 0) {
            state = "session";
            ui->display->setStyleSheet("background-color: rgb(85, 87, 83);");
            ui->display->clear();
        }
        if (ui->display->currentRow() == 1) {
            state = "records";
            ui->display->clear();
        }

    }
}
