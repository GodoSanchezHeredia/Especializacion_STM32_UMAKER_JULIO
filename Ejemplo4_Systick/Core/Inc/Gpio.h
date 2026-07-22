/*
 * Gpio.h
 *
 *  Created on: Jul 16, 2026
 *      Author: USER
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f401xe.h"
#include "stdint.h"
#include "stdbool.h"

//PA5 SALIDA
//PA PIN5 SALIDA SPEEDLOW PULLUP


//PC13 ENTRADA


#define PORT_A 1
#define PORT_B 2
#define PORT_C 3

 typedef enum{
	 INPUT = 0b00,
	 OUTPUT,
	 ALTERNATIVE,
	 ANALOG
 }GPIO_MODER;

 typedef enum{
	 NO_PULLUP_NO_PULL_DOWN,
	 PULL_UP,
	 PULL_DOWN,
 }GPIO_PUDR;

 typedef enum{
	 OUT2 = 0b00,
	 OUT25,
	 OUT50,
	 OUT100
 }GPIO_OSPEEDR;



void Gpio_Init(uint8_t port ,uint8_t pin , uint8_t mode , uint8_t speed , uint8_t pupd);
int Gpio_Read(uint8_t port , uint8_t pin);
void Gpio_Write(uint8_t port , uint8_t pin,bool state);
void Gpio_Toggle(uint8_t port , uint8_t pin);

#endif /* INC_GPIO_H_ */
