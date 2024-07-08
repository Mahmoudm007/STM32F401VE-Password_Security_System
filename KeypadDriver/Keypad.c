/**
 * Keypad.c
 *
 *  Created on: sun Apr 29 2024
 *  Author : Omar Abd El-Nasser
 */

#include "Keypad.h"

// Define the variable to hold the pressed key
uint8 pressedKey = 0;

// Function to initialize the keypad GPIO pins
void Keypad_Init(void) {
    uint8 index = 0;

    // Configure columns as output
    for (index = COL_START_INDEX; index <= COL_END_INDEX; index++) {
        Gpio_ConfigPin(COL_PORT, index, GPIO_INPUT, GPIO_PULL_UP);
    }

    // Configure rows as input with pull-up
    for (index = ROW_START_INDEX; index <= ROW_END_INDEX; index++) {
        Gpio_ConfigPin(ROW_PORT, index, GPIO_OUTPUT, GPIO_PUSH_PULL);
        Gpio_WritePin(ROW_PORT, index, KEYPAD_BTN_RELEASED);
    }
}

// Function to manage the keypad scanning
void Keypad_Manage(void) {
    uint8 row_idx = 0;
    uint8 col_idx = 0;

    for (row_idx = 0; row_idx < 4; row_idx++) {
        // Activate the current row
        Gpio_WritePin(ROW_PORT, ROW_START_INDEX + row_idx, KEYPAD_BTN_PRESSED);

        for (col_idx = 0; col_idx < 3; col_idx++) {
            // Check if a button in the current column is pressed
            if (GPIO_ReadPin(COL_PORT, COL_START_INDEX + col_idx) == KEYPAD_BTN_PRESSED) {
                // Calculate the pressed key based on the row and column indices
                pressedKey = keypad[row_idx][col_idx];
                // Notify the main program of the pressed key
                KeypadCallout_KeyPressNotification(pressedKey);
                // Break the loop since we found a pressed key
                break;
            }
        }

        // Deactivate the current row
        Gpio_WritePin(ROW_PORT, ROW_START_INDEX + row_idx, KEYPAD_BTN_RELEASED);
    }
}

// Function to get the pressed key
uint8 Keypad_GetKey(void) {
    return pressedKey;
}

// Define the key press notification callback function
void KeypadCallout_KeyPressNotification(uint8 pressedKey) {
    // This function will be implemented in main.c
    // You can perform any necessary actions based on the pressed key here
}
