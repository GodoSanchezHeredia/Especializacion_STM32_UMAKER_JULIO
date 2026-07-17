
#include "main.h"
#include "Clock_Config.h"
#include ""
//PA5

int main(void){

	 Init_Clock();

	  RCC->AHB1ENR |= (1 << 0);				 			//	Habilitamos el clock GPIOA
	  GPIOA->MODER |=  (1 << 10);			  			//	Configuración del PIN A5 como salida
	  GPIOA->MODER &= ~(1 << 11);
	  GPIOA->OTYPER &= ~(1 << 5);			 			//	0: Configuracion Output push-pull (reset state)
	  GPIOA->OSPEEDR &= ~(1 << 10)  & ~(1 << 11);			//	00: Configuración de la velocidad 2 MHz High speed
	  GPIOA->PUPDR &= ~(1 << 10) & ~(1 << 11);		    //	00: Configuración de resistencias  No pull-up, pull-dow

	for (;;) {

		GPIOA->ODR &=   ~(1<<5);
		__NOP();
		GPIOA->ODR |= (1<<5);
		__NOP();
	}


}
