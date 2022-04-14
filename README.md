# COMP3004 Team 8: OASIS Device Pro:

## Team Members
- Zachary Neath
    - Programming
    - Design
    - Diagrams & Documentation
- Alex Coyne
    - UI
    - Programming
    - Diagrams & Documentation
- Ade Banjo
    - Programming
    - Database
    - Diagrams & Documentation
- Ahsan Haleem
    - Diagrams & Documentation

## Selectable Options

- Sessions
    - Session Groups
        - 30 Minute
        - 45 Minute
        - 3 hours
        - User Designated
    - Session Types
        - MES
        - Sub-delta
        - Delta
        - Theta
        - Alpha
        - SMR
        - Beta
        - 100hz
- Records
    - View Session History


## Interactable Elements

- Oasis Pro Device
  - Power Button
  - Up Button
  - Down Button
  - Confirm Button

- Admin Panel
  - Battery Combobox
  - Connection ComboBox

## Design Decisions

- Mediator
    - We decided to use the mediator design patter to properly encapsulate the forward facing functionality of the UI and the back end business logic of the device.
    This makes it so that all important things are calculated and monitored by the device and the MainWindow updates the UI and tells the Device what it needs and
    what it's supposed to do.

- Power Function
    - Need to hold the power button to turn on and off.

- Battery Display
    - We decided that during the session run time every 4 seconds the graph would alternate between showing the intensity and showing the battery. This means that
    if you change the intensity while it's showing the battery it won't show the intensity until it swaps back. If it is already showing the intensity and you change
    it the timer updates the display every second so it might take a second to display.

- Recording
    - Recording is turned off by default. To record a session you must hold the confirm button when you are ready to move on from connection test.

- Record Viewing
    - Is done through a UI display that we added that is above the power button.

- Menu
    - We decided that there would be a menu to choose between operating the device and viewing records. This is done after the device turns on and appears in the display
    above the power button.

- User Designated Sessions
    - Based on the specifications we made it possible to potentially add a user designated session through the device, and we also made it possible to run user designated
    sessions. Because on the real device, user designated sessions are added via the David Session Editor so we decided to replicate that by having the ability to add user
    designated sessions through the device and database but not through the UI. So to be clear, you can't add a user session through the GUI and that's on purpose.
    
- Battery Replacement
    - If a battery is removed and then reinserted and the battery level is critical or lower we will assume that you replaced the battery and therefore the level will be
    reset to 100%. This is to replicate the fact that the device uses 9V disposable batteries.

## Test Cases

- Main Case
    - Passed
- Saving Records
    - Ran main use case with recording turned on.
    - Passed
- User Designated Cases
    - Ran user designated case
    - Passed
- Turning off during random events
    - Tested during: session, connection test, soft off, record view, menu, session select, paused session
    - Passed 
- Ran multiple sessions in a row
    - Passed
- Connection change during session
    - Passed
- Viewing Records
    - Passed
- Removing battery at random point:
    - Tested in: session, connection test, soft off, record view, menu, session select, paused session
    - Passed
