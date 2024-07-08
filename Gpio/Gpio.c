/**
 * Gpio.c
 *
 *  Created on: Sat Apr 19 2024
 *  Author    : Mahmoud Mohamed
 */

#include "Gpio.h"
#include "Gpio_Private.h"
#include "Bit_Operations.h"
#include "Utils.h"
#include "Rcc.h"

uint32 bit_pos = 0;

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState) {

	switch (PortName) {
	case GPIO_A:
		CLEAR_BIT_REG(GPIOA_MODER, 0x03, PinNum, 2);
		SET_BIT_REG(GPIOA_MODER, PinMode, PinNum, 2);
		switch(PinMode){
		case GPIO_OUTPUT:
			// switch case to set as open drain or push pull output register
			switch(DefaultState){
			case GPIO_PUSH_PULL:
				CLEAR_BIT_REG(GPIOA_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOA_OTYPER, DefaultState, PinNum, 1);
				break;
			case GPIO_OPEN_DRAIN:
				CLEAR_BIT_REG(GPIOA_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOA_OTYPER, DefaultState, PinNum, 1);
				break;
			}
			break;

		case GPIO_INPUT:
			switch(DefaultState){
			case GPIO_PULL_UP:
				CLEAR_BIT_REG(GPIOA_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOA_PUPDR, 0x01, PinNum, 2);
				break;
			case GPIO_PULL_DOWN:
				CLEAR_BIT_REG(GPIOA_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOA_PUPDR, 0x02, PinNum, 2);
				break;

			}
			break;
		}
		break;


	case GPIO_B:
		CLEAR_BIT_REG(GPIOB_MODER, 0x03, PinNum, 2);
		SET_BIT_REG(GPIOB_MODER, PinMode, PinNum, 2);
		switch(PinMode){
		case GPIO_OUTPUT:
			// switch case to set as open drain or push pull output register
			switch(DefaultState){
			case GPIO_PUSH_PULL:
				CLEAR_BIT_REG(GPIOB_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOB_OTYPER, DefaultState, PinNum, 1);
				break;
			case GPIO_OPEN_DRAIN:
				CLEAR_BIT_REG(GPIOB_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOB_OTYPER, DefaultState, PinNum, 1);
				break;
			}
			break;

		case GPIO_INPUT:
			switch(DefaultState){
			case GPIO_PULL_UP:
				CLEAR_BIT_REG(GPIOB_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOB_PUPDR, 0x01, PinNum, 2);
				break;
			case GPIO_PULL_DOWN:
				CLEAR_BIT_REG(GPIOB_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOB_PUPDR, 0x02, PinNum, 2);
				break;

			}
			break;
		}
		break;

	case GPIO_C:
		CLEAR_BIT_REG(GPIOC_MODER, 0x03, PinNum, 2);
		SET_BIT_REG(GPIOC_MODER, PinMode, PinNum, 2);
		switch(PinMode){
		case GPIO_OUTPUT:
			// switch case to set as open drain or push pull output register
			switch(DefaultState){
			case GPIO_PUSH_PULL:
				CLEAR_BIT_REG(GPIOC_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOC_OTYPER, DefaultState, PinNum, 1);
				break;
			case GPIO_OPEN_DRAIN:
				CLEAR_BIT_REG(GPIOC_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOC_OTYPER, DefaultState, PinNum, 1);
				break;
			}
			break;

		case GPIO_INPUT:
			switch(DefaultState){
			case GPIO_PULL_UP:
				CLEAR_BIT_REG(GPIOC_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOC_PUPDR, 0x01, PinNum, 2);
				break;
			case GPIO_PULL_DOWN:
				CLEAR_BIT_REG(GPIOC_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOC_PUPDR, 0x02, PinNum, 2);
				break;

			}
			break;
		}
		break;


	case GPIO_D:
		CLEAR_BIT_REG(GPIOD_MODER, 0x03, PinNum, 2);
		SET_BIT_REG(GPIOD_MODER, PinMode, PinNum, 2);
		switch(PinMode){
		case GPIO_OUTPUT:
			// switch case to set as open drain or push pull output register
			switch(DefaultState){
			case GPIO_PUSH_PULL:
				CLEAR_BIT_REG(GPIOD_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOD_OTYPER, DefaultState, PinNum, 1);
				break;
			case GPIO_OPEN_DRAIN:
				CLEAR_BIT_REG(GPIOD_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOD_OTYPER, DefaultState, PinNum, 1);
				break;
			}
			break;

		case GPIO_INPUT:
			switch(DefaultState){
			case GPIO_PULL_UP:
				CLEAR_BIT_REG(GPIOD_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOD_PUPDR, 0x01, PinNum, 2);
				break;
			case GPIO_PULL_DOWN:
				CLEAR_BIT_REG(GPIOD_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOD_PUPDR, 0x02, PinNum, 2);
				break;

			}
			break;
		}
		break;

	case GPIO_E:
		CLEAR_BIT_REG(GPIOE_MODER, 0x03, PinNum, 2);
		SET_BIT_REG(GPIOE_MODER, PinMode, PinNum, 2);
		switch(PinMode){
		case GPIO_OUTPUT:
			// switch case to set as open drain or push pull output register
			switch(DefaultState){
			case GPIO_PUSH_PULL:
				CLEAR_BIT_REG(GPIOE_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOE_OTYPER, DefaultState, PinNum, 1);
				break;
			case GPIO_OPEN_DRAIN:
				CLEAR_BIT_REG(GPIOE_OTYPER, 0x01, PinNum, 1);
				SET_BIT_REG(GPIOE_OTYPER, DefaultState, PinNum, 1);
				break;
			}
			break;

		case GPIO_INPUT:
			switch(DefaultState){
			case GPIO_PULL_UP:
				CLEAR_BIT_REG(GPIOE_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOE_PUPDR, 0x01, PinNum, 2);
				break;
			case GPIO_PULL_DOWN:
				CLEAR_BIT_REG(GPIOE_PUPDR, 0x03, PinNum, 2);
				SET_BIT_REG(GPIOE_PUPDR, 0x02, PinNum, 2);
				break;

			}
			break;
		}
		break;

	default:
		break;
	}
}

void GPIO_DISABLE_PINS(uint8 PortName){
	switch(PortName){
	case GPIO_A:
		  for (bit_pos = 0; bit_pos < 7; bit_pos++) {
			SET_BIT_REG(GPIOA_ODR, 0x03, bit_pos, 2);
		  }
		  Rcc_Disable(RCC_GPIOA);
	break;

	case GPIO_B:
		  for (bit_pos = 0; bit_pos < 7; bit_pos++) {
			SET_BIT_REG(GPIOB_ODR, 0x03, bit_pos, 2);
		  }
		  Rcc_Disable(RCC_GPIOB);
    break;

	case GPIO_C:
		  for (bit_pos = 0; bit_pos < 7; bit_pos++) {
			SET_BIT_REG(GPIOC_ODR, 0x03, bit_pos, 2);
		  }
		  Rcc_Disable(RCC_GPIOC);
	break;

	case GPIO_D:
		  for (bit_pos = 0; bit_pos < 7; bit_pos++) {
			SET_BIT_REG(GPIOD_ODR, 0x03, bit_pos, 2);
		  }
		  Rcc_Disable(RCC_GPIOD);
	break;

	case GPIO_E:
		  for (bit_pos = 0; bit_pos < 7; bit_pos++) {
			SET_BIT_REG(GPIOE_ODR, 0x03, bit_pos, 2);
		  }
		  Rcc_Disable(RCC_GPIOE);
	break;

	default:
		break;
	}
}

uint32 GPIO_ReadPin(uint8 PortName ,uint8 PinNumber){
	switch(PortName)
	{
	case GPIO_A:
		return READ_BIT_REG(GPIOA_IDR, 1, PinNumber, 1);
		break;
	case GPIO_B:
		return READ_BIT_REG(GPIOB_IDR, 1, PinNumber, 1);
		break;
	case GPIO_C:
		return READ_BIT_REG(GPIOC_IDR, 1, PinNumber, 1);
		break;
	case GPIO_D:
		return READ_BIT_REG(GPIOD_IDR, 1, PinNumber, 1);
		break;
	case GPIO_E:
		return READ_BIT_REG(GPIOE_IDR, 1, PinNumber, 1);
		break;
	default:
		break;
	}
	return NOK;
}

void GPIO_TogglePin(uint8 PortName, uint8 PinNum){
	switch(PortName){
	case GPIO_A:
		TOGGLE_BIT_REG(GPIOA_ODR, 1, PinNum, 1);
		break;
	case GPIO_B:
		TOGGLE_BIT_REG(GPIOB_ODR, 1, PinNum, 1);
		break;
	case GPIO_C:
		TOGGLE_BIT_REG(GPIOC_ODR, 1, PinNum, 1);
		break;
	case GPIO_D:
		TOGGLE_BIT_REG(GPIOD_ODR, 1, PinNum, 1);
		break;
	case GPIO_E:
		TOGGLE_BIT_REG(GPIOE_ODR, 1, PinNum, 1);
		break;
	default:
		break;
	}
}

uint32 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {
	// READ_BIT_REG(REGISTER, MASK,BIT_POS, CONTROL_BIT)

	uint8 check_GPIOA = READ_BIT_REG(GPIOA_MODER, 0x03, PinNum, 2);
	uint8 check_GPIOB = READ_BIT_REG(GPIOB_MODER, 0x03, PinNum, 2);
	uint8 check_GPIOC = READ_BIT_REG(GPIOC_MODER, 0x03, PinNum, 2);
	uint8 check_GPIOD = READ_BIT_REG(GPIOD_MODER, 0x03, PinNum, 2);
	uint8 check_GPIOE = READ_BIT_REG(GPIOE_MODER, 0x03, PinNum, 2);

		switch (PortName) {
		case GPIO_A:
			if(check_GPIOA){
//				CLEAR_BIT_REG(GPIOA_ODR, 0x1, PinNum, 1);
//				SET_BIT_REG(GPIOA_ODR, Data, PinNum, 1);
				GPIOA_ODR &= ~(0x1 << PinNum);
				GPIOA_ODR |= (Data << PinNum);
				return OK;
			}
			else{
				return NOK;
			}
			break;


		case GPIO_B:
			if(check_GPIOB){
				CLEAR_BIT_REG(GPIOB_ODR, 0x1, PinNum, 1);
				SET_BIT_REG(GPIOB_ODR, Data, PinNum, 1);
//				GPIOB_ODR &= ~(0x1 << PinNum);
//				GPIOB_ODR |= (Data << PinNum);
				return OK;
			}
			else{
				return NOK;
			}
			break;


		case GPIO_C:
			if(check_GPIOC){
				GPIOC_ODR &= ~(0x1 << PinNum);
				GPIOC_ODR |= (Data << PinNum);
				return OK;
			}
			else{
				return NOK;
			}
			break;


		case GPIO_D:
			if(check_GPIOD){
				GPIOD_ODR &= ~(0x1 << PinNum);
				GPIOD_ODR |= (Data << PinNum);
				return OK;
			}
			else{
				return NOK;
			}
			break;


		case GPIO_E:
			if(check_GPIOE){
				GPIOE_ODR &= ~(0x1 << PinNum);
				GPIOE_ODR |= (Data << PinNum);
				return OK;
			}
			else{
				return NOK;
			}
			break;

		default:
			break;
		}
		return NOK;
}
