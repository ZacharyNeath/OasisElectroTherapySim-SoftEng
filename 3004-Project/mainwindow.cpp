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

    connectElements();
    sessionSelectInitialization();

    //SESSION RECORD TESTING
    //QVector<Session*> sessionsVect;
    s1 = new Session("20 Minutes", "MET", 20, 3, true);
    s2 = new Session("45 Minutes", "Sub Delta", 45, 3, false);
    s3 = new Session("3 Hours", "Alpha", 180, 11, true);
    sessionsVect.push_back(s1);
    sessionsVect.push_back(s2);
    sessionsVect.push_back(s3);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete device;
    delete buttonTimer;
    delete [] groups;
    delete [] sessions;
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
    clearSessions();
    clearGroup();

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
    device->connectionTest();
    clearGraph();
    if (ui->electrodesComboBox->currentText() == "Excellent") {
        colourGraphNumber(0);
        colourGraphNumber(1);
        colourGraphNumber(2);
    }
    else if (ui->electrodesComboBox->currentText() == "Okay") {
        colourGraphNumber(3);
        colourGraphNumber(4);
        colourGraphNumber(5);
    }
    else if (ui->electrodesComboBox->currentText() == "Poor") {
        colourGraphNumber(6);
        colourGraphNumber(7);
    }
}

//END STATE UPDATES

//STORAGE QUERYING

//Gets records stored on device
QVector<Session*>* MainWindow::getRecords(){
    //Ask the device to get all (or perhaps limit it to like 20) records from storage
    return &sessionsVect;
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

    for(int i = 0; i<=numToLight; i++){
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
        case 0:
            label = ui->oneLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 1:
            label = ui->twoLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 2:
            label = ui->threeLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 3:
            label = ui->fourLabel;
            colour = "color: rgb(253,253,0);";
            break;
        case 4:
            label = ui->fiveLabel;
            colour = "color: rgb(253,253,0);";
            break;
        case 5:
            label = ui->sixLabel;
            colour = "color: rgb(253,253,0);";
            break;
        case 6:
            label = ui->sevenLabel;
            colour = "color: rgb(253,0,0);";
            break;
        case 7:
            label = ui->eightLabel;
            colour = "color: rgb(253,0,0);";
            break;
        default:
            return;
    }

    label->setStyleSheet(colour);
}

//Lights up a specific session
void MainWindow::colourSession(const int num){
    QString colour;
    QLabel* label;
    QLabel* frequency;

    switch(num){
        case 0:
            label = ui->metLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 1:
            label = ui->subDeltaLabel;
            frequency = ui->dutyCycleLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 2:
            label = ui->deltaLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 3:
            label = ui->thetaLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 4:
            label = ui->alphaLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 5:
            label = ui->smrLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 6:
            label = ui->betaLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 7:
            label = ui->hundredHzLabel;
            frequency = ui->shortPulseLabel;
            colour = "color: rgb(0,253,0);";
            break;
        default:
            return;
    }

    label->setStyleSheet(colour);
    frequency->setStyleSheet(colour);
}

//Lights up a specific group
void MainWindow::colourGroup(const int num){
    QString colour;
    QLabel* label;

    switch(num){
        case 0:
            label = ui->twentyMinLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 1:
            label = ui->fortyFiveMinLabel;
            colour = "color: rgb(0,253,0);";
            break;
        case 2:
            label = ui->threeHour;
            colour = "color: rgb(0,253,0);";
            break;
        case 3:
            label = ui->userDesigLabel;
            colour = "color: rgb(0,253,0);";
            break;
        default:
            return;
    }

    label->setStyleSheet(colour);
}

//Displays current records on UI
void MainWindow::displayRecords(QVector<Session*>*){
    for (int i = 0; i < sessionsVect.size(); ++i) {
        QListWidgetItem *session = new QListWidgetItem;
        QString cesMode = (sessionsVect[i]->getCES()?"Short-Pulse":"50% Duty Cycle");
        session->setText("Record :" + QString::number(i+1) + " - Date: " + sessionsVect[i]->getTimeString() + "\n Group: " + sessionsVect[i]->getGroup() + "\n Type: " + sessionsVect[i]->getType() + "\n Duration: "
                         + QString::number(sessionsVect[i]->getDuration()) + " Minutes\n Frequency: " + QString::number(sessionsVect[i]->getFrequency()) + "Hz\n CES Mode: " + cesMode + "\n----------");
        ui->display->insertItem(i, session);
    }
    ui->display->setCurrentRow(0);
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

//Turns off the lighting of the session
void MainWindow::clearSessions(){
    ui->metLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->subDeltaLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->deltaLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->thetaLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->alphaLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->smrLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->betaLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->hundredHzLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->shortPulseLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->dutyCycleLabel->setStyleSheet("color: rgb(85, 87, 83);");
}


//Turns off the lighting of the group
void MainWindow::clearGroup(){
    ui->twentyMinLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->fortyFiveMinLabel->setStyleSheet("color: rgb(85, 87, 83);");
    ui->threeHour->setStyleSheet("color: rgb(85, 87, 83);");
    ui->userDesigLabel->setStyleSheet("color: rgb(85, 87, 83);");
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

    //connect(ui -> electrodesComboBox, SIGNAL(), this, SLOT());
    //connect(ui -> batteryInComboBox, SIGNAL(), this, SLOT());
}

//Resets all button variables and timers when processing of a button is finished
void MainWindow::buttonReset(){
    buttonReleased = false;
    buttonHeldTime = 0;
    buttonTimer->stop();
    buttonTimer->disconnect();

}

//Initializes Session Selection Info
void MainWindow::sessionSelectInitialization() {
    currentGroup = 0;
    currentSession = 0;
    groups = new QLabel*[4];
    sessions = new QLabel*[8];

    //Assigns labels to the groups array
    groups[0] = ui->twentyMinLabel;
    groups[1] = ui->fortyFiveMinLabel;
    groups[2] = ui->threeHour;
    groups[3] = ui->userDesigLabel;

    sessions[0] = ui->metLabel;
    sessions[1] = ui->subDeltaLabel;
    sessions[2] = ui->deltaLabel;
    sessions[3] = ui->thetaLabel;
    sessions[4] = ui->alphaLabel;
    sessions[5] = ui->smrLabel;
    sessions[6] = ui->betaLabel;
    sessions[7] = ui->hundredHzLabel;
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
        if(device->getState()==DeviceState::SESSION_SELECT) {
            if(currentSession<sizeof(sessions)-1) {
                currentSession+=1;
                clearGraph();
                colourGraphNumber(currentSession);
                clearSessions();
                colourSession(currentSession);
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
        if(device->getState()==DeviceState::SESSION_SELECT) {
            if(currentSession>0) {
                currentSession-=1;
                clearGraph();
                colourGraphNumber(currentSession);
                clearSessions();
                colourSession(currentSession);
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
        if(device->getState()==DeviceState::SESSION_SELECT) {
            if(currentGroup<(sizeof(groups)/2)) {
                currentGroup+=1;
                clearGroup();
                colourGroup(currentGroup);
                colourSession(currentSession);
                if (currentGroup == (sizeof(groups)/2)-1) {
                    clearGraph();
                    clearSessions();
                    currentSession = -1;
                }
            }
            if(currentGroup==(sizeof(groups)/2)) {
                currentGroup = 0;
                currentSession = 0;
                clearGroup();
                colourGroup(currentGroup);
                colourSession(currentSession);
                colourGraphNumber(0);
            }
        }
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
                currentGroup = 0;
                currentSession = 0;
                colourGraphNumber(currentSession);
                colourGroup(currentGroup);
                colourSession(currentSession);
                return;
            }
            //If record mode is selected
            else if (ui->display->currentRow() == 1) {
                device->recordView();
                ui->display->clear();
                displayRecords(getRecords());
                return;
            }
        }
        if (device->getState()==DeviceState::SESSION_SELECT) {
            device->Device::createSession(currentGroup, currentSession);
            connectionTest();
            return;
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
