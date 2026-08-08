/*
 * ADC.c
 *
 *  Created on: Aug 7, 2026
 *      Author: USER
 */
#include "ADC.h"
#include "stm32f4xx.h"
#include "Systick.h"

void adc_init(void){
	//habilitamos reloj del adc
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;//(1<<8)

	//HABILITAR EL GPIOa
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//habilitanmos el clok del gpioA
	GPIOA->MODER |= (1<<0)|(1<<1);//GPIO_MODER_MODE0

	ADC1->CR1 &= ~(ADC_CR1_RES);// 0 0 -> 12 bits

	ADC1->CR2 &= ~(ADC_CR2_ALIGN);//alineado a la derecha

	ADC1->CR2 &= ~(ADC_CR2_CONT);//single mode

	ADC1->SMPR2 &= ~((1<<2)|(1<<1)|(1<<0));
	//ADC1->SMPR2 |= (1<<0);//15 cycles

	//clock
	ADC->CCR &= ~(ADC_CCR_ADCPRE);//16/2 = 8MHZ

	//conversiones
	ADC1->SQR1 &= ~(ADC_SQR1_L);
	ADC1->SQR3 =0;

	//ADC1->CR2 |= ADC_CR2_SWSTART;
	//ADC1->CR2 |= ADC_CR2_ADON;

	__delay_ms(10);
}

void adc_start(void){
	ADC1->SR = 0;//limpiamos todas las flags
	ADC1->CR2 |= ADC_CR2_ADON;

	ADC1->CR2 |= ADC_CR2_SWSTART;
}

void adc_stop(void){
	ADC1->SR = 0;
	ADC1->CR2 &= ~(ADC_CR2_SWSTART);

}

bool adc_pollendconversion(uint16_t timeout){

	uint32_t startime = msgetTick();
	while((ADC1->SR & ADC_SR_EOC)== 0){

		if ((msgetTick()-startime)>timeout) {
			return false;
		}
	}
	return true;
}

uint16_t AnalogRead(void){

	return ((ADC1->DR) & 0x0fff);//12 bits
}


void adc_EnableNVIC(void){
	ADC1->CR1 |= ADC_CR1_EOCIE;//habilitmaos las interrupciones
	__NVIC_SetPriority(ADC_IRQn, 2);//DEFINIMOS PRIORIDAD
	__NVIC_EnableIRQ(ADC_IRQn);//HABILITAMO
}

void adc_DisableNVIC(void){

	ADC1->CR1 &= ~(ADC_CR1_EOCIE) ;
	__NVIC_DisableIRQ(ADC_IRQn);
}
