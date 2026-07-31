/*
 * Systick.h
 *
 *  Created on: Jul 21, 2026
 *      Author: USER
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


#include <stm32f4xx.h>

void SystickConfig(uint32_t SystickVal);

void msIncTick(void);
uint32_t msgetTick(void);

void __delay_ms(uint32_t delay);

#endif /* SYSTICK_H_ */
