/*
 * Timer.c
 *
 *  Created on: Aug 6, 2026
 *      Author: USER
 */


#include "Timer.h"
#include "stm32f4xx.h"

void Timer_delay_init(uint32_t aut){
		RCC->APB1ENR |= (1<<0);//TIM2 ENABLE

		//INDICAMOS DIR  // UP //DOWN
		TIM2->CR1 &= ~(1<<4);// MODO ASCENDENTE

		//ONE PULSE MODE
		TIM2->CR1 |= (1<<3);

		//MODE RESET
		TIM2->CR2 &= ~(TIM_CR2_MMS);

		//PRESCALER
		TIM2->PSC=0;
		//ARR
		TIM2->ARR = aut -1;//0.1ms

}

void Timer_delay(uint32_t delay){

	//50ms
	//50*10 =500
	TIM2->PSC=(delay*10)-1;
	//habilitamos el contador
	TIM2->CR1 |= (1<<0);

	while(!(TIM2->SR & TIM_SR_UIF));
	TIM2->SR &= ~(TIM_SR_UIF);

}


//timer periodic
void Timer_periodit_init(uint32_t delay,uint32_t arr){

	RCC->APB1ENR |= (1<<0);//TIM2 ENABLE

	TIM2->CR1 &= ~(1<<4);// MODO ASCENDENTE

	TIM2->CR1 &= ~(1<<3);// recarga - no pulse mode
	//MODE RESET

	TIM2->CR2 &= ~(TIM_CR2_MMS);

	//PRESCALER
	TIM2->PSC=(delay*10)-1;
	//ARR
	TIM2->ARR = arr -1;//

	TIM2->SR &= ~(TIM_SR_UIF);

	TIM2->DIER |= (1<<0);//enable interrupt


	__NVIC_SetPriority(TIM2_IRQn, 2);//DEFINIMOS PRIORIDAD

	__NVIC_EnableIRQ(TIM2_IRQn);//HABILITAMOS

	//habilitamos el contador
		TIM2->CR1 |= (1<<0);


}


void TIM2_IRQHandler(void){

	__NVIC_ClearPendingIRQ(TIM2_IRQn);
	TIM2->SR &= ~(TIM_SR_UIF);

	GPIOA->ODR ^= (1<<5);
}

