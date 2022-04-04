#include "mainwindow.h"
#include "ui_mainwindow.h"

//CONST & DEST

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonHeldTime = 0;
    buttonReleased = false;

    device = new Device();
    buttonTimer = new QTimer(this);

    connectButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete device;
    delete buttonTimer;
}

//END CONST & DEST

//STATE UPDATES

//The power on process for the unit
void MainWindow::powerOn(){
    // Encapsulate all powering on stuff here
    // Probably just turn on basic stuff on allow the user
    // To choose between the record window and doing a session
    ui->powerIndicatorLabel->setStyleSheet("color: rgb(138, 226, 52)");
    ui->display->setStyleSheet("background-color: rgb(255, 255, 255);");

    displayMenu();
    displayBattery();

    device->powerOn();
}

//The power off process for the unit
void MainWindow::powerOff(){
    // Encapsulate all powering off stuff
    // updates UI
    // Ends program
    ui -> powerIndicatorLabel->setStyleSheet("color: rgb(85, 87, 83);");
    clearMenu();
    clearGraph();

    device->powerOff();
}

//Tells unit to enter soft off mode
void MainWindow::softOff(){
    // Can be called from battery being too low
    // Can be called from the power button being held
    // Tells unit to enter soft off state

}

//Tells the device to enter session select mode
void MainWindow::enterSessionSelect(){
    // Update display
    clearMenu();
    clearGraph();
    device->enterSessionSelect();
}

//Tells the device to enter Session state
void MainWindow::startSession(){
    //Also starts the timer and links it to the updateStatus func
}

//Triggered when the session ends to do things necessary to when a session ends
void MainWindow::endSession(){
    // Does any UI updating if necessary
    // Tells Device session is over
    // Then calls SoftOff

}

//Called when a session has been selected
void MainWindow::connectionTest(){
    //tells device to enter connection test mode
    //Update UI to reflect the current test

}

//END STATE UPDATES

//STORAGE QUERYING

//Gets records stored on device
QVector<Session*>* MainWindow::getRecords(){
    //Ask the device to get all (or perhaps limit it to like 20) records from storage
}

//Gets all details for a record and displays them in the list window
Session* MainWindow::getRecordDetails(){
    // Ask the device to query for a specific record
}

//Get information for a specific user session
Session* MainWindow::getUserSession(){
    //Find highlighted label and query device for detail relating to that session
}

//END STORAGE QUERYING

//UI UPDATES

//Updates graph to show current battery level
void MainWindow::displayBattery(){
    //Query device for battery level
    // The graph is numbers 1-8 so:
        //numToLightUp = floor(batteryLevel/12.5)
    double battery = device->getBatteryLevel();
    int numToLight = (int)(ceil((battery/12.5)));

    for(int i = 1; i<=numToLight; i++){
        colourGraphNumber(i);
    }
}

//Update graph to show current intensity
void MainWindow::displayIntensity(){
    //Query device for intensity level
}

//Lights up a specific number of the graph
void MainWindow::colourGraphNumber(const int num){
    QString colour;
    QLabel* label;

    switch(num){
        case 1:
            label = ui->oneLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 2:
            label = ui->twoLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 3:
            label = ui->threeLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 4:
            label = ui->fourLabel;
            colour = "color: rgb(253,253,0);";
            break;
        case 5:
            label = ui->fiveLabel;
            colour = "color: rgb(253,253,0);";
            break;
        case 6:
            label = ui->sixLabel;
            colour = "color: rgb(253,253,0);";
            break;
        case 7:
            label = ui->sevenLabel;
            colour = "color: rgb(253,0,0);";
            break;
        case 8:
            label = ui->eightLabel;
            colour = "color: rgb(253,0,0);";
            break;
        default:
            return;
    }

    label->setStyleSheet(colour);
}

//Displays current records on UI
void MainWindow::displayRecords(QVector<Session*>*){

}

//Displays current session information on UI
void MainWindow::displaySession(Session*){

}

//Displays initial menu between session selection and record viewing
void MainWindow::displayMenu(){
    //Populates the display options
    QListWidgetItem *session = new QListWidgetItem;
    session->setText("Select a session");
    ui->display->insertItem(0, session);

    QListWidgetItem *records = new QListWidgetItem;
    records->setText("View records");
    ui->display->insertItem(1, records);

    ui->display->setCurrentItem(session);
}

//Turns off the lighting on all numbers on the graph
void MainWindow::clearGraph(){
    ui->oneLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->twoLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->threeLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->fourLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->fiveLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->sixLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->sevenLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->eightLabel->setStyleSheet("color: rgb(85, 87, 83);");
}

//Clears record window
void MainWindow::clearMenu(){
    ui->display->clear();
    ui->display->setStyleSheet("background-color: rgb(85, 87, 83);");
}

//Sets all highlighted elements back to normal
void MainWindow::clearUI(){

}


//END UI UPDATES

//HELPERS

//Helper to form all connections
void MainWindow::connectElements() {
    connect(ui -> intUpButton, SIGNAL(pressed()), this, SLOT(upPressed()));
    connect(ui -> intDownButton, SIGNAL(pressed()), this, SLOT(downPressed()));
    connect(ui -> powerButton, SIGNAL(pressed()), this, SLOT(powerPressed()));
    connect(ui -> confirmButton, SIGNAL(pressed()), this, SLOT(confirmPressed()));

    connect(ui -> intUpButton, SIGNAL(released()), this, SLOT(buttonRelease()));
    connect(ui -> intDownButton, SIGNAL(released()), this, SLOT(buttonRelease()));
    connect(ui -> powerButton, SIGNAL(released()), this, SLOT(buttonRelease()));
    connect(ui -> confirmButton, SIGNAL(released()), this, SLOT(buttonRelease()));
}

//Resets all button variables and timers when processing of a button is finished
void MainWindow::buttonReset(){
    buttonReleased = false;
    buttonHeldTime = 0;
    buttonTimer->stop();
    buttonTimer->disconnect();

}

//END HELPERS

//SLOTS

//DRIVERS

//Runs and tells unit to update itself depending on its state
void MainWindow::updateStatus() {
    //For more details on how it repeats
    //https://doc.qt.io/qt-5/qtimer.html#details
    // tells unit to update one timestep
    // turns off if device has turned off

}

//END DRIVERS

//Executes if up has been pressed on main window
void MainWindow::upPressed() {
    //Execution depends on device state
            //If in record menu it navigates
            //If in session select it navigates Session Type
            //If in session it increases intensity
    if(!buttonReleased && !(buttonTimer->isActive())){
        connect(buttonTimer, &QTimer::timeout, this, &MainWindow::upPressed);
        buttonTimer->start(20);
        return;
    }

    if(!buttonReleased){
        ++buttonHeldTime;
    }

    //Consider button "held" after 2 seconds
    if(buttonHeldTime>=100){
        buttonReset();
        upHeld();
    }

    //If button wasn't held proceed as normal
    if(buttonReleased && buttonHeldTime < 100){
        buttonReset();
        if(device->getState()==DeviceState::MENU || device->getState()==DeviceState::RECORDS){
            if(ui->display->currentRow()!=0){
                ui->display->setCurrentRow(ui->display->currentRow()-1);
            }
        }
    }
}

//Executes if up has been pressed on main window
void MainWindow::downPressed() {
    //Execution depends on device state
            //If in record menu it navigates
            //If in session select it navigates Session Type
            //If in session it decreases intensity

    if(!buttonReleased && !(buttonTimer->isActive())){
        connect(buttonTimer, &QTimer::timeout, this, &MainWindow::downPressed);
        buttonTimer->start(20);
        return;
    }

    if(!buttonReleased){
        ++buttonHeldTime;
    }

    //Consider button "held" after 2 seconds
    if(buttonHeldTime>=100){
        buttonReset();
        downHeld();
    }

    //If button wasn't held proceed as normal
    if(buttonReleased && buttonHeldTime < 100){
        buttonReset();
        if(device->getState()==DeviceState::MENU || device->getState()==DeviceState::RECORDS){
            if(ui->display->currentRow()!=ui->display->count()-1){
                ui->display->setCurrentRow(ui->display->currentRow()+1);
            }
        }
    }
}

//Executes if the power button has been pressed
void MainWindow::powerPressed(){
    //Execution depends on device state
        // If in session select it changes session group
        // If viewing a record it returns to record menu (basically a back button)

    //If button has just been pressed start timer
    if(!buttonReleased && !(buttonTimer->isActive())){
        connect(buttonTimer, &QTimer::timeout, this, &MainWindow::powerPressed);
        buttonTimer->start(20);
        return;
    }

    if(!buttonReleased){
        ++buttonHeldTime;
    }

    qInfo() << "Time: " << buttonHeldTime;
    qInfo() << "Released? " << buttonReleased;
    //Consider button "held" after 2 seconds
    if(buttonHeldTime>=100){
        buttonReset();
        powerHeld();
    }

    //If button wasn't held proceed as normal
    if(buttonReleased && buttonHeldTime < 100){
        buttonReset();
    }
}

//Executes if the confirm button has been pressed
void MainWindow::confirmPressed() {
    // If in record menu it selects record to view
    // If in session select it confirms selection
    // Starts session when in connection test

    if(!buttonReleased && !(buttonTimer->isActive())){
        connect(buttonTimer, &QTimer::timeout, this, &MainWindow::confirmPressed);
        buttonTimer->start(20);
        return;
    }

    if(!buttonReleased){
        ++buttonHeldTime;
    }

    //Consider button "held" after 2 seconds
    if(buttonHeldTime>=100){
        buttonReset();
        confirmHeld();
    }

    //If button wasn't held proceed as normal
    if(buttonReleased && buttonHeldTime < 100){
        buttonReset();
        if (device->getState()==DeviceState::MENU) {
            //If session mode selected
            if (ui->display->currentRow() == 0) {
                enterSessionSelect();

            }
            //If record mode is selected
            else if (ui->display->currentRow() == 1) {
                device->recordView();
                ui->display->clear();
            }
        }

    }

}



//END PRESSED


//HELD

//Executes if up has been held
void MainWindow::upHeld() {
    //Only works during session select
    //Increases intensity for every second held

}

//Executes if down has been held
void MainWindow::downHeld() {
    //Only works during session select
        //Decreases intensity for every second held

}

//Executes if the power button has been held
void MainWindow::powerHeld() {
    //If device off it turns on
        //Should call powerOn process
    //If device on it turns off
        // Should call softOff process

    if(device->getState()==DeviceState::OFF){
        powerOn();
    }
    else{
        //This is temporary. Normally we'd need to go through the soft off process
        powerOff();
    }

}

//Executes if the confirm button has been held
void MainWindow::confirmHeld() {
    // Will only work during connection test
    // Turns recording on for the session and starts session

}

//END HELD

//RELEASED

void MainWindow::buttonRelease(){
    if(buttonTimer->isActive()){
        buttonReleased = true;
    }
}

//END RELEASED

//COMBO UPDATE

//Executes when the connection combo box changes
void MainWindow::connectionUpdate() {
    //Updates unit with new connection status
    // Only update display if in connection test

}

//Updates battery status
void MainWindow::batteryChange() {
    // Updates the devices battery status e.g. whether it’s inserted
}

//END COMBO UPDATE

//END SLOTS
