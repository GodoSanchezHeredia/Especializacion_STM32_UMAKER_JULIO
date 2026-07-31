/*
 * Display.c
 *
 *  Created on: Jul 27, 2026
 *      Author: USER
 */
#include "Display.h"
#include "Systick.h"

static void Disable_AllDigits(void){
	GPIOB ->ODR |= 1<<0;
	GPIOA ->ODR |= 1<<0;
	GPIOA ->ODR |= 1<<1;
	GPIOA ->ODR |= 1<<4;
}

static void  Selec_Display( DisplayNum Dis_Select){

	Disable_AllDigits();

	if (Dis_Select == Display1) {
		GPIOB ->ODR &= ~(1<<0);
		__delay_ms(10);
		GPIOB ->ODR |= 1<<0;
	}
	if (Dis_Select == Display2) {
		GPIOA ->ODR &= ~(1<<4);
		__delay_ms(10);
		GPIOA ->ODR |= 1<<4;
	}
	if (Dis_Select == Display3) {
		GPIOA->ODR &= ~(1<<1);
		__delay_ms(10);
		GPIOA ->ODR |= 1<<1;
	}
	if (Dis_Select == Display4) {
		GPIOA ->ODR &= ~(1<<0);
		__delay_ms(10);
		GPIOA ->ODR |= 1<<0;
	}


}


void Display7SegInit(Display7Seg *Display){


	Gpio_Init(PORT_A, Display->a, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_A, Display->b, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_B, Display->c, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_B, Display->d, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_B, Display->e, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_B, Display->f, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_A, Display->g, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);

	Gpio_Init(PORT_A, 0, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_A, 1, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_A, 4, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	Gpio_Init(PORT_B, 0, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);


}


void Write_Display7Seg(Display7Seg *Display,DisplayNum Dis_Selec,uint8_t val ){
	//const uint8_t Display_7Seg_C[] = {0X3F,0X06,0X5B,0X4,0X66,0X6D,0X7D,0X07,0X7F,0X67};
	const uint8_t Display_7Seg_A[] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

	uint8_t dato = Display_7Seg_A[val];

	ResetDisplay7Seg();
	if (dato & 0x1)   GPIOA ->ODR |= 1<<Display->a;
	if (dato & 1<<1)  GPIOA ->ODR |= 1<<Display->b;
	if (dato & 1<<2)  GPIOB ->ODR |= 1<<Display->c;
	if (dato & 1<<3)  GPIOB ->ODR |= 1<<Display->d;
	if (dato & 1<<4)  GPIOB ->ODR |= 1<<Display->e;
	if (dato & 1<<5)  GPIOB ->ODR |= 1<<Display->f;
	if (dato & 1<<6)  GPIOA ->ODR |= 1<<Display->g;

	/*multiplexacion*/
	Selec_Display(Dis_Selec);
}

void ResetDisplay7Seg(void){

Gpio_Write(PORT_A,9, 0);
Gpio_Write(PORT_A, 8 ,0);
Gpio_Write(PORT_B, 10, 0);
Gpio_Write(PORT_B, 4, 0);
Gpio_Write(PORT_B, 5, 0);
Gpio_Write(PORT_B, 3, 0);
Gpio_Write(PORT_A, 10, 0);

}

