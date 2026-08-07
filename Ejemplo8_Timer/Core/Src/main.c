
#include "main.h"
#include "Clock_Config.h"
#include "Gpio.h"
#include "Systick.h"
#include "Display.h"
#include "ExtInt.h"
#include "defines.h"
#include "USART.h"
#include "Timer.h"



volatile uint32_t i = 0;



int main(void){

	 Init_Clock_HSE();
	 SystickConfig(16000);
	 //Timer_delay_init(8400);
	 Timer_periodit_init(2000, 8400);
	 Gpio_Init(PORT_A, 5,OUTPUT	, OUT2, NO_PULLUP_NO_PULL_DOWN);
	 Gpio_Init(PORT_C, 13, INPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);

	for (;;) {

		//Gpio_Toggle(PORT_A, 5);
		//Timer_delay(100);

	}


}

