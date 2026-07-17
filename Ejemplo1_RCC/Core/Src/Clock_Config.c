/*
 * Clock_Config.c
 *
 *  Created on: Jul 14, 2026
 *      Author: USER
 */


#include "Clock_Config.h"
#include "stdint.h"
#include "stm32f401xe.h"

void Init_Clock(void){

	//FLASH LATENCY 16 MHZ HSI
	FLASH ->ACR &= ~((1<<3)|(1<<2)|(1<<1)|(1<<0));//0000 ZERO WAIT STATE+
	FLASH ->ACR |= ((1<<11)|(1<<10)|(1<<9)|(1<<8)); //ART ACCELATOR

	//HABILITAR EL HSI
	RCC->CR |= (1<<0); //HSION
	while(!(RCC ->CR & RCC_CR_HSION));

}
