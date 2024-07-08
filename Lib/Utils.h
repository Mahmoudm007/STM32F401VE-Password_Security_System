/**
 * Utils.h
 *
 *  Created on: Sat Apr 19 2024
 *  Author    : Omar Abd El-nasser
 */
#ifndef UTILS_H
#define UTILS_H

#include "Std_Types.h"
#define REG32(BASE_ADDR, OFFSET)  (*(uint32 *)((BASE_ADDR) + (OFFSET)))

#define OK    (return_status)0x01
#define NOK   (return_status)0x00


#define True  (return_status)0x01
#define False (return_status)0x00

#endif /* UTILS_H */
