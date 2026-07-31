/*
 * Clock_Config.c
 *
 *  Created on: Jul 14, 2026
 *      Author: USER
 */


#include "Clock_Config.h"
#include "stdint.h"
#include "stm32f401xe.h"

void Init_Clock_HSI(void){

	//FLASH LATENCY 16 MHZ HSI
	FLASH ->ACR &= ~((1<<3)|(1<<2)|(1<<1)|(1<<0));//0000 ZERO WAIT STATE+
	FLASH ->ACR |= ((1<<11)|(1<<10)|(1<<9)|(1<<8)); //ART ACCELATOR

	//HABILITAR EL HSI
	RCC->CR |= (1<<0); //HSION
	while(!(RCC ->CR & RCC_CR_HSION));

}


void Init_Clock_HSE(void){

	/*
	 * 8MHz -> 84MHz
	 * AHB 1
	 * APB1 2
	 * APB2 1
	 * */

	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);//LIMPIAMOS EL REGISTRO PLLCFGR
	RCC->PLLCFGR |= (PLL_M) | (PLL_N<<6) | (PLL_P<<16);//CARGAMOS LOS VALORES DEL PLL


	//HSE
	RCC->CR  |= RCC_CR_HSEON;
	while(!(RCC->CR & (1<<17)));//hse ready esperamos q active

	RCC->PLLCFGR |= (1<<22);//habilitamos el pll

	//pll on
	RCC->CR  |= RCC_CR_PLLON;
	while(!(RCC->CR & (1<<25)));//pll ready esperamos q active

	//flash
	FLASH->ACR &= ~(FLASH_ACR_LATENCY);//limpiamos
	FLASH ->ACR &= ~((1<<3)|(1<<2)|(1<<0));//0010 ZERO WAIT STATE
	FLASH ->ACR |= (1<<1);
	FLASH ->ACR |= ((1<<11)|(1<<10)|(1<<9)|(1<<8)); //ART ACCELATOR

	//seleccion del mux del clock

	RCC->CFGR &= ~(RCC_CFGR_SW);//limpiamos el selector de clock
	RCC->CFGR |= (1<<1);
	RCC->CFGR &= ~(1<<0);//seleccion el pll

	while(!(RCC->CFGR & (RCC_CFGR_SW_PLL)));

	//prescaladores

	RCC->CFGR &= ~(RCC_CFGR_HPRE);// 00000-> 1  AHB

	RCC->CFGR &= ~(RCC_CFGR_PPRE1);
	RCC->CFGR |= (RCC_CFGR_PPRE1_2);// /2 APB1

	RCC->CFGR &= ~(RCC_CFGR_PPRE2);//APB2

 }
