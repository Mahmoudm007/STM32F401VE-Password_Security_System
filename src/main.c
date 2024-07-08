#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Bit_Operations.h"
#include "Keypad.h"

// Variables to use
#define Delay_time     100000
volatile unsigned int Status = 1;

// Define the patterns for each digit
const uint8 digitPatterns[10][7] = {
    {0, 1, 1, 1, 1, 1, 1}, // 0
    {0, 0, 0, 0, 1, 1, 0}, // 1
    {1, 0, 1, 1, 0, 1, 1}, // 2
    {1, 0, 0, 1, 1, 1, 1}, // 3
    {1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 1, 0, 1, 1, 0, 1}, // 5
    {1, 1, 1, 1, 1, 0, 1}, // 6
    {0, 0, 0, 0, 1, 1, 1}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 0, 1, 1, 1, 1}  // 9
};

// Define the keypad matrix (4x3 matrix)
char keypad[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

// Define an array to store keypad input
char userInput[4] = {'\0'};

// Index to track current position in userInput array
uint8 userInputIndex = 0;

// Function to set the GPIO pins based on the digit
void setDigit(uint8 digit) {
    for (int i = 0; i < 7; i++) {
        Gpio_WritePin(GPIO_A, i, digitPatterns[digit][i] ? HIGH : LOW);
        DELAY(1000);
    }
}

// Delay function
void DELAY(unsigned long timeinMILLS) {
    volatile unsigned int i = 0;
    volatile unsigned int j = 0;

    for (i = 0; i < timeinMILLS; i++) {
        // to avoid the warning of the for loop is not guarded
        for (j = 0; j < 2; j++);
    }
}

// Initialize GPIO pins
void INIT_GPIOS_PINS() {
    uint32 i = 0;
    for (i = 0; i < 7; i++) {
        Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
    }
    // Initialize Port C Pin 0 and Pin 1 as output
    Gpio_ConfigPin(GPIO_C, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_C, 1, GPIO_OUTPUT, GPIO_PUSH_PULL);
}

// Disable GPIO pins
void DISABLE_GPIO_PINS() {
    GPIO_DISABLE_PINS(GPIO_A);
    GPIO_DISABLE_PINS(GPIO_B);
    GPIO_DISABLE_PINS(GPIO_C);
    GPIO_DISABLE_PINS(GPIO_D);
    GPIO_DISABLE_PINS(GPIO_E);
}

// Enable RCC peripherals
void RCC_ENABLE() {
    Rcc_Init();
    Rcc_Enable(RCC_GPIOA);
    Rcc_Enable(RCC_GPIOB);
    Rcc_Enable(RCC_GPIOC);
    Rcc_Enable(RCC_GPIOD);
    Rcc_Enable(RCC_GPIOE);
}

// Disable RCC peripherals
void RCC_DISABLE() {
    Rcc_Disable(RCC_GPIOA);
    Rcc_Disable(RCC_GPIOB);
    Rcc_Disable(RCC_GPIOC);
    Rcc_Disable(RCC_GPIOD);
    Rcc_Disable(RCC_GPIOE);
}

int main() {
    // Enable RCC peripherals
    RCC_ENABLE();

    // Initialize GPIO pins for keypad and LED
    INIT_GPIOS_PINS();
    Keypad_Init();

    // Define the correct password
    char correctPassword[4] = {'1', '1', '1', '1'};

    // Main loop
    while (Status == 1) {
        // Scan keypad for input
        Keypad_Manage();

        // Get the pressed key
        uint8 pressedKey = Keypad_GetKey();

        // Check if the pressed key is a valid digit or '#' or '*'
        if ((pressedKey >= '0' && pressedKey <= '9') || pressedKey == '#' || pressedKey == '*') {
            // If '#' is pressed, compare userInput with correctPassword
            if (pressedKey == '#') {
                // Reset userInputIndex for the next input sequence
                userInputIndex = 0;

                // Compare userInput with correctPassword
                int isEqual = 1;
                for (int i = 0; i < 4; i++) {
                    if (userInput[i] != correctPassword[i]) {
                        isEqual = 0;
                        break; // Exit the loop early if any character doesn't match
                    }
                }

                // Turn on LED based on the result of comparison
                if (isEqual) {
                    // Turn on LED connected to Port C Pin 0
                    Gpio_WritePin(GPIO_C, 0, HIGH);
                    // Turn off LED connected to Port C Pin 1
                    Gpio_WritePin(GPIO_C, 1, LOW);
                } else {
                    // Turn on LED connected to Port C Pin 1
                    Gpio_WritePin(GPIO_C, 1, HIGH);
                    // Turn off LED connected to Port C Pin 0
                    Gpio_WritePin(GPIO_C, 0, LOW);
                }
            } else if (pressedKey == '*') {
                // Clear userInput array
                for (int i = 0; i < 4; i++) {
                    userInput[i] = '\0';
                }
                userInputIndex = 0;
            } else {
                // Store the key in userInput array
                if (userInputIndex < 4) {
                    userInput[userInputIndex++] = pressedKey;
                }

                // If a valid digit is pressed, display it on the 7-segment display
                int digit = pressedKey - '0';
                setDigit(digit);
            }
        }

        // Delay to prevent rapid key scanning
        DELAY(10000);
    }

    // Disable GPIO pins and RCC peripherals
    DISABLE_GPIO_PINS();
    RCC_DISABLE();

    return 0;
}
