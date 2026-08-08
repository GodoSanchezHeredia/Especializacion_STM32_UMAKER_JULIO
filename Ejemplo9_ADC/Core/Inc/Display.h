/*
 * Display.h
 *
 *  Created on: Jul 27, 2026
 *      Author: USER
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "stm32f401xe.h"
#include "stdint.h"
#include "stdbool.h"
#include "Gpio.h"


typedef struct
{
	uint8_t a;//PA9
	uint8_t b;//PA8
	uint8_t c;//PB10
	uint8_t d;//PB4
	uint8_t e;//PB5
	uint8_t f;//PB3
	uint8_t g;//PA10
}Display7Seg;

typedef enum{
Display1=1,
Display2,
Display3,
Display4
}DisplayNum;

void Display7SegInit(Display7Seg *Display);
void Write_Display7Seg(Display7Seg *Display,DisplayNum Dis_Selec,uint8_t val );
void ResetDisplay7Seg(void);
#endif /* INC_DISPLAY_H_ */
