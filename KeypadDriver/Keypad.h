
/**
 * Keypad.h
 *
 *  Created on: sun Apr 29 2024
 *  Author    : Omar Abd El-Nasser
 */

#ifndef KEYPADDRIVER_H
#define KEYPADDRIVER_H

#include "Std_Types.h"
#include "Gpio.h"

#define COL_PORT  GPIO_B
#define COL_START_INDEX 0
#define COL_END_INDEX 2

#define ROW_PORT GPIO_B
#define ROW_START_INDEX 12
#define ROW_END_INDEX 15

// For Active Low
#define KEYPAD_BTN_PRESSED 0
#define KEYPAD_BTN_RELEASED 1


//extern uint8 pressedKey; // Declare key as extern
extern char keypad[4][3];

void Keypad_Init(void);
void Keypad_Manage(void);
uint8 Keypad_GetKey(void);


// required function implemented by application
void KeypadCallout_KeyPressNotificaton(uint8 pressedKey);


#endif /* KEYPAD_H */
