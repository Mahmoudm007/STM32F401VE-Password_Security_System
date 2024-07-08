/**
 * Rcc_Private.h
 *
 *  Created on: Sat Apr 19 2024
 *  Author    : Omar Abd El-nasser
 */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "Std_Types.h"
#include "Utils.h"

#define RCC_BASE_ADDR       0x40023800					 // Base of RCC registers
#define RCC_CR              REG32(RCC_BASE_ADDR, 0x00)   // clock control register
#define RCC_PLLCFGR         REG32(RCC_BASE_ADDR, 0x04UL) // PLL configuration register
#define RCC_CFGR            REG32(RCC_BASE_ADDR, 0x08UL) // clock configuration register
#define RCC_CIR             REG32(RCC_BASE_ADDR, 0x0CUL) // clock interrupt register
#define RCC_AHB1RSTR        REG32(RCC_BASE_ADDR, 0x10UL) // AHB1 peripheral reset register
#define RCC_AHB2RSTR        REG32(RCC_BASE_ADDR, 0x14UL) // AHB2 peripheral reset register
#define RCC_AHB3RSTR        REG32(RCC_BASE_ADDR, 0x18UL) // AHB3 peripheral reset register
#define RCC_APB1RSTR        REG32(RCC_BASE_ADDR, 0x20UL) // APB1 peripheral reset register
#define RCC_APB2RSTR        REG32(RCC_BASE_ADDR, 0x24UL) // APB2 peripheral reset register
#define RCC_AHB1ENR         REG32(RCC_BASE_ADDR, 0x30UL) // AHB1 peripheral clock enable register
#define RCC_AHB2ENR         REG32(RCC_BASE_ADDR, 0x34UL) // AHB2 peripheral clock enable register
#define RCC_AHB3ENR         REG32(RCC_BASE_ADDR, 0x38UL) // AHB3 peripheral clock enable register
#define RCC_APB1ENR         REG32(RCC_BASE_ADDR, 0x40UL) // APB1 peripheral clock enable register
#define RCC_APB2ENR         REG32(RCC_BASE_ADDR, 0x44UL) // APB2 peripheral clock enable register
#define RCC_AHB1LPENR       REG32(RCC_BASE_ADDR, 0x50UL) // AHB1 peripheral clock enable in low power mode register
#define RCC_AHB2LPENR       REG32(RCC_BASE_ADDR, 0x54UL) // AHB2 peripheral clock enable in low power mode register
#define RCC_AHB3LPENR       REG32(RCC_BASE_ADDR, 0x58UL) // AHB3 peripheral clock enable in low power mode register
#define RCC_APB1LPENR       REG32(RCC_BASE_ADDR, 0x60UL) // APB1 peripheral clock enable in low power mode register
#define RCC_APB2LPENR       REG32(RCC_BASE_ADDR, 0x64UL) // APB2 peripheral clock enable in low power mode register
#define RCC_BDCR            REG32(RCC_BASE_ADDR, 0x70UL) // Backup domain control register
#define RCC_CSR             REG32(RCC_BASE_ADDR, 0x74UL) // clock control & status register
#define RCC_SSCGR           REG32(RCC_BASE_ADDR, 0x80UL) // spread spectrum clock generation register
#define RCC_PLLI2SCFGR      REG32(RCC_BASE_ADDR, 0x84UL) // PLLI2S configuration register
#define RCC_DCKCFGR			REG32(RCC_BASE_ADDR, 0x80UL) // Dedicated Clocks Configuration Register



/*
 * @param : Register is the register i want to set
 * @param : mask is the number of bits like 1, 3, 7
 * @param : Bit position the position of the bit i want to set the mask in it
 * @param : C0ntrol bit is the number of bits that control the pin mode
 * */

// Clock enable for GPIOs
#define RCC_CLOCK_GPIOA_ENABLE SET_BIT(RCC_AHB1ENR, 1, 0, 1);
#define RCC_CLOCK_GPIOB_ENABLE SET_BIT(RCC_AHB1ENR, 1, 1, 1);
#define RCC_CLOCK_GPIOC_ENABLE SET_BIT(RCC_AHB1ENR, 1, 2, 1);
#define RCC_CLOCK_GPIOD_ENABLE SET_BIT(RCC_AHB1ENR, 1, 3, 1);
#define RCC_CLOCK_GPIOE_ENABLE SET_BIT(RCC_AHB1ENR, 1, 4, 1);


// Clock reset for GPIOs
#define RCC_CLOCK_GPIOA_RESET  CLEAR_BIT(RCC_AHB1ENR, 1, 0, 1);
#define RCC_CLOCK_GPIOB_RESET  CLEAR_BIT(RCC_AHB1ENR, 1, 1, 1);
#define RCC_CLOCK_GPIOC_RESET  CLEAR_BIT(RCC_AHB1ENR, 1, 2, 1);
#define RCC_CLOCK_GPIOD_RESET  CLEAR_BIT(RCC_AHB1ENR, 1, 3, 1);
#define RCC_CLOCK_GPIOE_RESET  CLEAR_BIT(RCC_AHB1ENR, 1, 4, 1);

#endif /* RCC_PRIVATE_H */
