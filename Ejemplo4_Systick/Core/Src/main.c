
#include "main.h"
#include "Clock_Config.h"
#include "Gpio.h"
#include "Systick.h"
//PA5

int main(void){

	 Init_Clock_HSI();
	 SystickConfig(16000);
	 Gpio_Init(PORT_A, 5, OUTPUT,OUT2,NO_PULLUP_NO_PULL_DOWN);
	 Gpio_Init(PORT_C, 13, INPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);

	for (;;) {

		Gpio_Write(PORT_A, 5, true);
		__delay_ms(100);
		Gpio_Write(PORT_A, 5, false);
		__delay_ms(100);
/*
		if (!Gpio_Read(PORT_C, 13)) {
			Gpio_Toggle(PORT_A, 5);
			for(uint32_t var = 0;var<=100000;var ++);
		}else{
			Gpio_Write(PORT_A, 5, false);

		}*/

	}


}
