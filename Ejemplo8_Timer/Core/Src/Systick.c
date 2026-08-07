/*
 * Systick.c
 *
 *  Created on: Jul 21, 2026
 *      Author: USER
 */
#include "Systick.h"

static __IO uint32_t mstick;

void SystickConfig(uint32_t SystickVal){

	SysTick->CTRL = 0;// limpiamos el buffer

	//cargar el valor
	SysTick->LOAD = SystickVal-1; //0-83999

	SysTick->CTRL |= 	(1<<2) | //1: Processor clock (AHB)
						(1<<1) | //1: Counting down to zero to asserts the SysTick exception request
						(1<<0); //1: Counter enabled

	__NVIC_SetPriority(SysTick_IRQn, 0);
}

void SysTick_Handler(void){
	__NVIC_ClearPendingIRQ(SysTick_IRQn);
	msIncTick();
}

void msIncTick(void){
	mstick++;
}
uint32_t msgetTick(void){

return mstick;
}
//__delay _delay
void __delay_ms(uint32_t delay){

	uint32_t startime = msgetTick();

	while ((msgetTick()-startime)<delay);

}
