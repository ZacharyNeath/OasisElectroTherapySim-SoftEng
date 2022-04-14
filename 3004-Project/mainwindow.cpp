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
    graphFlag = false;

    device = new Device();
    buttonTimer = new QTimer(this);

    connectionUpdate();
    batteryChange();

    connectElements();
    sessionSelectInitialization();
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
    ui->powerIndicatorLabel->setStyleSheet("color: rgb(138, 226, 52)");
    ui->display->setStyleSheet("background-color: rgb(255, 255, 255);");

    displayMenu();
    displayBattery();

    device->powerOn();
}

//The power off process for the unit
void MainWindow::powerOff(){
    ui -> powerIndicatorLabel->setStyleSheet("color: rgb(85, 87, 83);");
    clearMenu();
    clearGraph();
    clearSessions();
    clearGroup();

    device->powerOff();
}

//Tells unit to enter soft off mode
void MainWindow::softOff(){
    device->softOff();
}

//Tells the device to enter session select mode
void MainWindow::enterSessionSelect(){
    clearMenu();
    clearGraph();
    device->enterSessionSelect();
}

//Tells the device to enter Session state, starts the timer, and links it to the updateStatus func
void MainWindow::startSession(){
    clearGraph();
    displayIntensity();
    QTimer* sessionTimer = device->getSessionTimer();

    //If session was already underway resume it
    if(!(sessionTimer->isActive())){
        connect(sessionTimer, &QTimer::timeout, this, &MainWindow::updateStatus);
        sessionTimer->start(1000);
    }
    device->startSession();
}

//Triggered when the session ends and tells Device session is over
void MainWindow::endSession(){
    device->endSession();
    softOff();
}

//Tells device to enter connection test mode and updates UI to reflect the current test
void MainWindow::connectionTest(){
    device->connectionTest();
    clearGraph();
    displayConnection();
}

//END STATE UPDATES


//STORAGE QUERYING

//Gets records stored on device
QVector<Session*>* MainWindow::getRecords(){
    return device->getRecords();
}

//Get information for a specific user session
Session* MainWindow::getUserSession(){
    Session* sess = device->getUserSession(currentSession);

    if(sess==nullptr){
        currentSession = -1;
    }

    return sess;
}

//END STORAGE QUERYING


//UI UPDATES

//Updates graph to show current battery level
void MainWindow::displayBattery(){
    double battery = device->getBatteryLevel();
    int numToLight = (int)(ceil((battery/12.5)))-1;

    for(int i = 0; i<=numToLight; i++){
        colourGraphNumber(i);
    }
}

//Update graph to show current intensity
void MainWindow::displayIntensity(){
    int intensity = device->getIntensity()-1;
    for(int i = 0; i<=intensity; i++){
        colourGraphNumber(i);
    }
}

//Displays device connection on graph
void MainWindow::displayConnection(){
    switch(device->getConnectionLevel()){
        case 2:
            colourGraphNumber(0);
            colourGraphNumber(1);
            colourGraphNumber(2);
            break;
        case 1:
            colourGraphNumber(3);
            colourGraphNumber(4);
            colourGraphNumber(5);
            break;
        case 0:
            colourGraphNumber(6);
            colourGraphNumber(7);
            break;
        default:
            return;
    }
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
    QLabel* label;
    QLabel* frequency;

    switch(num){
        case 0:
            label = ui->metLabel;
            frequency = ui->shortPulseLabel;
            break;
        case 1:
            label = ui->subDeltaLabel;
            frequency = ui->dutyCycleLabel;
            break;
        case 2:
            label = ui->deltaLabel;
            frequency = ui->shortPulseLabel;
            break;
        case 3:
            label = ui->thetaLabel;
            frequency = ui->shortPulseLabel;
            break;
        case 4:
            label = ui->alphaLabel;
            frequency = ui->shortPulseLabel;
            break;
        case 5:
            label = ui->smrLabel;
            frequency = ui->shortPulseLabel;
            break;
        case 6:
            label = ui->betaLabel;
            frequency = ui->shortPulseLabel;
            break;
        case 7:
            label = ui->hundredHzLabel;
            frequency = ui->shortPulseLabel;
            break;
        default:
            return;
    }

    label->setStyleSheet("color: rgb(0,253,0);");
    frequency->setStyleSheet("color: rgb(0,253,0);");
}

//Lights up a specific group
void MainWindow::colourGroup(const int num){
    QLabel* label;

    switch(num){
        case 0:
            label = ui->twentyMinLabel;
            break;
        case 1:
            label = ui->fortyFiveMinLabel;
            break;
        case 2:
            label = ui->threeHour;
            break;
        case 3:
            label = ui->userDesigLabel;
            break;
        default:
            return;
    }

    label->setStyleSheet("color: rgb(0,253,0);");
}

//Displays current records on UI
void MainWindow::displayRecords(QVector<Session*>* sessions){
    QVector<Session*>sessionsVect = *(sessions);

    for (int i = 0; i < sessionsVect.size(); ++i) {
        QListWidgetItem *session = new QListWidgetItem;
        QString cesMode = (sessionsVect[i]->getCES()?"Short-Pulse":"50% Duty Cycle");
        session->setText("Record :" + QString::number(i+1) + " - Date: " + sessionsVect[i]->getTimeString() + "\n Group: " + sessionsVect[i]->getGroup() + "\n Type: " + sessionsVect[i]->getType() + "\n Duration: "
                         + QString::number(sessionsVect[i]->timeElapsed()) + " Minutes\n Frequency: " + QString::number(sessionsVect[i]->getFrequency()) + "Hz\n CES Mode: " + cesMode + "\n----------");
        ui->display->insertItem(i, session);
    }

    ui->display->setCurrentRow(0);
}

//Displays current session information on UI
void MainWindow::displaySession(Session* session){
    int frequency = session->getFrequency();
    bool ces = session->getCES();
    int freqNum = 0;

    switch(frequency){
        case 3:
            freqNum = 0;
            break;
        case 5:
            freqNum = 2;
            break;
        case 8:
            freqNum = 3;
            break;
        case 11:
            freqNum = 4;
            break;
        case 15:
            freqNum = 5;
            break;
        case 22:
            freqNum = 6;
            break;
        case 100:
            freqNum = 7;
            break;
    }

    colourGraphNumber(currentSession);
    colourSession(freqNum);
    if(ces){
        ui->shortPulseLabel->setStyleSheet("color: rgb(0,253,0);");
        ui->dutyCycleLabel->setStyleSheet("color: rgb(85, 87, 83);");
    }
    else{
        ui->shortPulseLabel->setStyleSheet("color: rgb(85, 87, 83);");
        ui->dutyCycleLabel->setStyleSheet("color: rgb(0,253,0);");
    }

}

//Displays initial menu between session selection and record viewing
void MainWindow::displayMenu(){
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

    connect(ui -> electrodesComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(connectionUpdate()));
    connect(ui -> batteryInComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(batteryChange()));
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

    //Assigns labels to the groups array
    groups.append(ui->twentyMinLabel);
    groups.append(ui->fortyFiveMinLabel);
    groups.append(ui->threeHour);
    groups.append(ui->userDesigLabel);

    sessions.append(ui->metLabel);
    sessions.append(ui->subDeltaLabel);
    sessions.append(ui->deltaLabel);
    sessions.append(ui->thetaLabel);
    sessions.append(ui->alphaLabel);
    sessions.append(ui->smrLabel);
    sessions.append(ui->betaLabel);
    sessions.append(ui->hundredHzLabel);
}

//END HELPERS


//SLOTS

//DRIVERS

//Runs and tells unit to update itself depending on its state
void MainWindow::updateStatus() {
    device->updateStatus();
    int remainder = device->getSessionRemainder();

    if((device->batteryCritical() || remainder==0 )&& device->getState()!=SOFT_OFF){
        device->endSession();
    }

    if(device->getState()==DeviceState::SOFT_OFF && device->getIntensity()==0){
        powerOff();
        device->killSession();
        return;
    }
    else if(device->getState()==DeviceState::SOFT_OFF){ //device in soft off
        clearGraph();
        displayIntensity();
    }
    else if(device->getState()==DeviceState::SESSION){
        clearGraph();
        if(remainder%4==0){//Determine whether to display intensity or battery
            graphFlag = !graphFlag;
        }
        if(graphFlag){
            displayIntensity();
        }
        else{
            displayBattery();
        }
    }
}

//END DRIVERS

//Executes if up has been pressed on main window
void MainWindow::upPressed() {
    //Execution depends on device state
            //If in record menu it navigates
            //If in session select it navigates Session Type
            //If in session it increases intensity


    if(device->getState()==DeviceState::MENU || device->getState()==DeviceState::RECORDS){
        if(ui->display->currentRow()!=0){
            ui->display->setCurrentRow(ui->display->currentRow()-1);
        }
    }
    if(device->getState()==DeviceState::SESSION_SELECT) {
        if(currentGroup==groups.count()-1){//If we're in user designated
            //Don't load anything if no sessions exist
            if(currentSession==-1){
                return;
            }
            else{ //Otherwise get the next session from the db
                int temp = currentSession;
                ++currentSession;
                Session* userDesig = getUserSession();
                if(userDesig==nullptr){
                    currentSession = temp;
                    return;
                }
                clearGraph();
                clearSessions();
                displaySession(userDesig);
                return;
            }
        }
        else if(currentSession<sessions.count()-1) { //Triggers if not in user desig
            currentSession+=1;
        }

        clearGraph();
        colourGraphNumber(currentSession);
        clearSessions();
        colourSession(currentSession);

    }
    else if(device->getState()==DeviceState::SESSION){
        device->increaseIntensity();
    }
}

//Executes if up has been pressed on main window
void MainWindow::downPressed() {
    //Execution depends on device state
            //If in record menu it navigates
            //If in session select it navigates Session Type
            //If in session it decreases intensity

    if(device->getState()==DeviceState::MENU || device->getState()==DeviceState::RECORDS){
        if(ui->display->currentRow()!=ui->display->count()-1){
            ui->display->setCurrentRow(ui->display->currentRow()+1);
        }
    }
    else if(device->getState()==DeviceState::SESSION_SELECT) {
        if(currentGroup==groups.count()-1){
            if(currentSession==-1){
                return;
            }
            else if(currentSession>0){
                --currentSession;
                Session* userDesig = getUserSession();
                clearGraph();
                clearSessions();
                displaySession(userDesig);
                return;
            }
        }
        else if(currentSession>0) {
            currentSession-=1;
        }
        clearGraph();
        colourGraphNumber(currentSession);
        clearSessions();
        colourSession(currentSession);
    }
    else if(device->getState()==DeviceState::SESSION){
        device->decreaseIntensity();
    }
}

//Executes if the power button has been pressed
void MainWindow::powerPressed(){
    //Execution depends on device state
        // If in session select it changes session group
        // If viewing a record it returns to record menu (basically a back button)

    //If button has just been pressed start timer
    if(!(device->isBatteryIn())){
        return;
    }

    if(!buttonReleased && !(buttonTimer->isActive())){
        connect(buttonTimer, &QTimer::timeout, this, &MainWindow::powerPressed);
        buttonTimer->start(20);
        return;
    }

    if(!buttonReleased){
        ++buttonHeldTime;
    }

    //Consider button "held" after 2 seconds
    if(buttonHeldTime>=100){
        buttonReset();
        powerHeld();
    }

    //If button wasn't held proceed as normal
    if(buttonReleased && buttonHeldTime < 100){
        buttonReset();
        if(device->getState()==DeviceState::SESSION_SELECT) {
            if(currentGroup<groups.count()-1) {
                currentGroup+=1;
            }
            else if(currentGroup==groups.count()-1) {
                currentGroup = 0;
                currentSession = 0;
            }

            if(currentGroup==groups.count()-1){
                currentSession = 0;
            }

            clearGroup();
            clearSessions();
            clearGraph();

            //Covers when we first navigate to user sessions
            if (currentGroup == groups.count()-1) {
                Session* currUserSession = getUserSession();
                if(currentSession!=-1){
                    displaySession(currUserSession);
                }
                colourGroup(currentGroup);
                return;
            }

            colourGroup(currentGroup);
            colourSession(currentSession);
            colourGraphNumber(currentSession);

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

        else if(device->getState()==DeviceState::SESSION_SELECT) {
            if(currentGroup<groups.count()-1){
                device->createSession(currentGroup, currentSession);
                connectionTest();
            }
            else if(currentSession!=-1){
                Session* userSess = getUserSession();
                device->acceptUserSession(userSess);
                connectionTest();
            }
            return;
        }

        else if(device->getState()==DeviceState::CONNECTION_TEST){
            if(device->getConnectionLevel()>0){
                startSession();
            }
            return;
        }
    }

}

//END PRESSED


//HELD

//Executes if the power button has been held
void MainWindow::powerHeld() {
    //If device off it turns on
        //Should call powerOn process
    //If device on it turns off
        // Should call softOff process

    if(device->getState()==DeviceState::OFF){
        powerOn();
    }
    else if(device->getState()==DeviceState::SESSION || device->getState()==DeviceState::CONNECTION_TEST){
        device->endSession();
        softOff();
    }
    else if(device->getState()==DeviceState::SOFT_OFF){

    }
    else{
        powerOff();
    }

}

//Executes if the confirm button has been held
void MainWindow::confirmHeld() {
    // Will only work during connection test
    // Turns recording on for the session and starts session
    if(device->getState()==DeviceState::CONNECTION_TEST){
        if(device->getConnectionLevel()>0){
            device->turnOnRecording();
            startSession();
        }
    }

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
    int connection = ui->electrodesComboBox->currentIndex();
    device->setConnection(connection);

    if(device->getState()==DeviceState::CONNECTION_TEST){
        clearGraph();
        displayConnection();
    }
    else if(device->getState()==DeviceState::SESSION){
        if(connection==0){
            connectionTest();
        }
    }

}

//Updates battery status
void MainWindow::batteryChange() {
    // Updates the devices battery status e.g. whether it’s inserted
    int battery = ui->batteryInComboBox->currentIndex();
    device->setBattery(battery);

    if(!(device->isBatteryIn())){
        device->killSession();
        powerOff();
    }
}

//END COMBO UPDATE


//END SLOTS
