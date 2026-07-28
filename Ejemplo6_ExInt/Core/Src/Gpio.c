/*
 * Gpio.c
 *
 *  Created on: Jul 16, 2026
 *      Author: USER
 */

#include "Gpio.h"



void Gpio_Init(uint8_t port ,uint8_t pin , uint8_t mode , uint8_t speed , uint8_t pupd){

	switch (port) {
		case PORT_A:

			  RCC->AHB1ENR |= (1 << 0);				 			//	Habilitamos el clock GPIOA
			  GPIOA->MODER |= (mode<<2*pin);
			  if (mode == 1) {
				GPIOA->MODER &= ~(mode<<2*pin+1);
				GPIOA ->OTYPER &= ~(1<<pin);
				GPIOA ->OSPEEDR |= (speed<<2*pin);
			  }
			  GPIOA->PUPDR |= (pupd<<2*pin);
			break;
		case PORT_B:

			  RCC->AHB1ENR |= (1 << 1);				 			//	Habilitamos el clock GPIOA
			  GPIOB->MODER |= (mode<<2*pin);
			  if (mode == 1) {
				  GPIOB->MODER &= ~(mode<<2*pin+1);
				  GPIOB ->OTYPER &= ~(1<<pin);
				  GPIOB ->OSPEEDR |= (speed<<2*pin);
			  }
			  GPIOB->PUPDR |= (pupd<<2*pin);
			break;
		case PORT_C:

			  RCC->AHB1ENR |= (1 << 2);				 			//	Habilitamos el clock GPIOA
			  GPIOC->MODER |= (mode<<2*pin);
			  if (mode == 1) {
				  GPIOC->MODER &= ~(mode<<2*pin+1);
				  GPIOC ->OTYPER &= ~(1<<pin);
				  GPIOC ->OSPEEDR |= (speed<<2*pin);
			  }
			  GPIOC->PUPDR |= (pupd<<2*pin);
			break;
		default:
			break;
	}
}

int Gpio_Read(uint8_t port , uint8_t pin){
 int state = 0;

	 switch (port) {
		case PORT_A:
			state = (GPIOA->IDR & (1<<pin));
			break;
		case PORT_B:
			state = (GPIOB->IDR & (1<<pin));
			break;
		case PORT_C:
			state = (GPIOC->IDR & (1<<pin));
			break;
		default:
			break;
	}
	 return state;
}

void Gpio_Write(uint8_t port , uint8_t pin,bool state){

	switch (port) {
		case PORT_A:
			switch (state) {
				case true:
					GPIOA->ODR  |= (1<<pin);
					break;
				case false:
					GPIOA->ODR &= ~(1<<pin);
					break;
			}
			break;
		case PORT_B:
			switch (state) {
				case true:
					GPIOB->ODR  |= (1<<pin);
					break;
				case false:
					GPIOB->ODR &= ~(1<<pin);
					break;
			}
			break;
		case PORT_C:
			switch (state) {
				case true:
					GPIOC->ODR  |= (1<<pin);
					break;
				case false:
					GPIOC->ODR &= ~(1<<pin);
					break;
			}
				break;
		default:
			break;
	}



}
void Gpio_Toggle(uint8_t port , uint8_t pin){
	switch (port) {
		case PORT_A:
			GPIOA->ODR ^= (1<<pin);

			break;
		case PORT_B:
			GPIOB->ODR ^= (1<<pin);

			break;
		case PORT_C:
			GPIOC->ODR ^= (1<<pin);

				break;
		default:
			break;
	}
}
