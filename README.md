[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/EaClDaQ_)



# Keypad Lock System

# Overview
The Keypad Lock System is a simple embedded system that allows users to enter a password via a keypad. Once the correct password is entered, the system unlocks and activates an LED. The system is designed to be easily customizable and extensible for different applications.

# Features
- Simple password entry using a 4x3 keypad
- LED indication for lock/unlock status
- 7-segment display to show the currently pressed key
- Ability to customize the correct password and LED behavior
- When the '#' clicked the entered passwoed compared with correct password and if they are equal the GREEN LED turned ON, if false RED LED turned ON
- Option to reset the entered password and start over using '*' in teh keypad
 

# Usage
1. Connect the keypad, 7-segment display, and LED to the microcontroller as per the hardware setup.
2. Open the project in STM32CubeIDE.
3. Configure the GPIO pins for keypad, 7-segment display, and LED in the `main.c` file.
4. Adjust the correct password and LED behavior as needed in the `main.c` file.
5. Build and flash the firmware to the microcontroller.
6. Power up the system and enter the password via the keypad.
7. If the correct password is entered, the LED will indicate the unlock status.

# The password is 1111 "you can change it as you like"
![Alt Text](assets/pass.gif)
