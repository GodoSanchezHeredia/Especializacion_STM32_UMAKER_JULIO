/*
 * ExtInt.c
 *
 *  Created on: Jul 27, 2026
 *      Author: USER
 */

#include "ExtInt.h"
#include "stm32f401xe.h"
 volatile uint32_t i ;

void ExternInterrupt_Init(void){
	//habilitamos el reloj
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	/*
	 *
	 *Conectar el PC13 CON LA LINEA EXT13
	 *y le indicamos que esta en el PC
	 */
	SYSCFG ->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13;
	SYSCFG ->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

	//desemasacaramos para permitir interrupciones
	EXTI->IMR |= EXTI_IMR_IM13;
	EXTI->EMR |= EXTI_EMR_EM13;

	//PULL UP DESCENDENTE

	EXTI->FTSR |= EXTI_FTSR_TR13;
	//DESABILITAMOS RISING
	EXTI->RTSR &= ~EXTI_RTSR_TR13;

	__NVIC_SetPriority(EXTI15_10_IRQn, 1);//DEFINIMOS PRIORIDAD

	__NVIC_EnableIRQ(EXTI15_10_IRQn);//HABILITAMOS


}
void EXTI15_10_IRQHandler(void){

	__NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
	EXTI->PR |= EXTI_PR_PR13;

	i++;
}

