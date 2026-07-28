
#include "main.h"
#include "Clock_Config.h"
#include "Gpio.h"
#include "Systick.h"
#include "Display.h"
//PA5

Display7Seg Display_1 ={9,8,10,4,5,3,10};
uint8_t unidades =0,decenas=0 , centenas=0 , mil=0 ;
uint32_t i = 0;

int main(void){

	 Init_Clock_HSI();
	 SystickConfig(16000);
	 Display7SegInit(&Display_1);

	for (;;) {

		mil= i/1000;
		centenas = (i%1000)/100;
		decenas= (i%100)/10;
		unidades= (i%10);

		Write_Display7Seg(&Display_1, Display1, unidades);
		Write_Display7Seg(&Display_1, Display2, decenas);
		Write_Display7Seg(&Display_1, Display3, centenas);
		Write_Display7Seg(&Display_1, Display4, mil);
		i++;
		if (i == 10000) i = 0;
	}


}
