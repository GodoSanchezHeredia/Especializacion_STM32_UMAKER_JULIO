/*
 * ADC.h
 *
 *  Created on: Aug 7, 2026
 *      Author: USER
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stdint.h"
#include "stdbool.h"

#define AN0 0b0000
#define AN1 0b0001
#define AN2 0b0010
#define AN3 0b0011
#define AN4 0b0100
#define AN5 0b0101
#define AN6 0b0110
#define AN7 0b0111
#define AN8 0b1000
#define AN9 0b1001
#define AN10 01010
#define AN11 0b1011
#define AN12 0b1100
#define AN13 0b1101
#define AN14 0b1110
#define AN15 0b1111



void adc_init(void);
void adc_start(void);
void adc_stop(void);
bool adc_pollendconversion(uint16_t timeout);
uint16_t AnalogRead(void);
void adc_EnableNVIC(void);
void adc_DisableNVIC(void);
#endif /* INC_ADC_H_ */
