
#include "main.h"
#include "Clock_Config.h"
#include "Gpio.h"
#include "Systick.h"
#include "Display.h"
#include "ExtInt.h"
#include "defines.h"
#include "USART.h"
#include "Timer.h"
#include "ADC.h"


volatile uint16_t adc_result = 0;
volatile float voltaje = 0;
bool flag = false;


int main(void){

	 Init_Clock_HSI();
	 SystickConfig(16000);
	 Gpio_Init(PORT_A, 5, OUTPUT, OUT2, NO_PULLUP_NO_PULL_DOWN);
	 adc_init();
	 adc_start();
	 adc_EnableNVIC();
	for (;;) {

/* ejemplo polling
		adc_start();
		flag = adc_pollendconversion(5);
		if (flag==1) {
			adc_result = AnalogRead();
			voltaje = adc_result*(3.3/4095);
			adc_stop();
		}
		Gpio_Toggle(PORT_A, 5);

		__delay_ms(100);
*/
		if (flag) {
			voltaje = adc_result*(3.3/4095);
			flag = false;
			adc_start();
		}

	}


}

void ADC_IRQHandler(void){

	__NVIC_ClearPendingIRQ(ADC_IRQn);
	ADC1->SR &= ~ (ADC_SR_EOC);
	adc_result = AnalogRead();
	flag = true;
}

