/**
 * Gpio.h
 *
 *  Created on: Sat Apr 19 2024
 *  Author    : Mahmoud Mohamed
 */

#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"

/*PortName*/
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'
#define GPIO_E 'E'

/*PinMode*/
#define GPIO_INPUT  				0x00
#define GPIO_OUTPUT 				0x01
#define GPIO_ALTERNATE_FUNCTION     0x02
#define GPIO_ANALOG 				0x03

/*DefaultState*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01

#define GPIO_PULL_UP	0x01
#define GPIO_PULL_DOWN	0x02

/*DefaultState Input*/
#define GPIO_INPUT_PULL_UP 0x01
#define GPIO_INPUT_PULL_DOWN 0x02

/* Port output speed controller*/
#define GPIO_OSPEED_LOW_SPEED 		0x00
#define GPIO_OSPEED_MEDIUM_SPEED 	0x01
#define GPIO_OSPEED_HIGH_SPEED 		0x02
#define GPIO_OSPEED_VERY_HIGH_SPEED 0x03

/* Port configuration lock register*/
#define GPIO_NOT_LOCKED 0x00
#define GPIO_LOCKED 	0x01

/*Data*/
#define LOW  0x00
#define HIGH 0x01


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);
uint32 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);
uint32 GPIO_ReadPin(uint8 PortName, uint8 PinNum);
void GPIO_TogglePin(uint8 PortName, uint8 PinNum);
void GPIO_DISABLE_PINS(uint8 PortName);

#endif /* GPIO_H */
