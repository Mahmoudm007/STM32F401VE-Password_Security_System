/**
 * Rcc.c
 *
 *  Created on: Sat Apr 19 2024
 *  Author    : Omar Abd El-nasser
 */

#include "Rcc.h"
#include "Bit_Operations.h"
#include "Rcc_Private.h"
#include "Std_Types.h"


void Rcc_Init(void) {
	SET_BIT_REG(RCC_CR, 1, 0 ,1);
}

void Rcc_Enable(Rcc_PeripheralIdType PeripheralId) {
  uint8 BusId = PeripheralId / 32;
  uint8 PeripheralBitPosition = PeripheralId % 32;
  switch (BusId) {
    case RCC_AHB1:
    	// SET_BIT(RCC_AHB1ENR, 1, 0, 1);
    	SET_BIT_REG(RCC_AHB1ENR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_AHB1ENR, PeripheralBitPosition);
      break;

    case RCC_AHB2:
    	SET_BIT_REG(RCC_AHB2ENR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_AHB2ENR, PeripheralBitPosition);
      break;

    case RCC_APB1:
    	SET_BIT_REG(RCC_APB1ENR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_APB1ENR, PeripheralBitPosition);
      break;

    case RCC_APB2:
    	SET_BIT_REG(RCC_APB2ENR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_APB2ENR, PeripheralBitPosition);
      break;
    default:
      break;
  }
}

void Rcc_Disable(Rcc_PeripheralIdType PeripheralId) {
     uint8 BusId = PeripheralId / 32;
  uint8 PeripheralBitPosition = PeripheralId % 32;
  switch (BusId) {
    case RCC_AHB1:
    	SET_BIT_REG(RCC_AHB1RSTR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_AHB1RSTR, PeripheralBitPosition);
      break;
    case RCC_AHB2:
    	SET_BIT_REG(RCC_AHB2RSTR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_AHB2RSTR, PeripheralBitPosition);
      break;
    case RCC_APB1:
    	SET_BIT_REG(RCC_APB1RSTR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_APB1RSTR, PeripheralBitPosition);
      break;
    case RCC_APB2:
    	SET_BIT_REG(RCC_APB2RSTR, 1, PeripheralBitPosition,1);
//      SET_BIT(RCC_APB2RSTR, PeripheralBitPosition);
      break;
    default:
      break;
  }
}
