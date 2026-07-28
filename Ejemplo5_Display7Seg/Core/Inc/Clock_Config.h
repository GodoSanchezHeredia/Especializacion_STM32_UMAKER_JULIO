/*
 * Clock_Config.h
 *
 *  Created on: Jul 14, 2026
 *      Author: USER
 */

#ifndef INC_CLOCK_CONFIG_H_
#define INC_CLOCK_CONFIG_H_


/*
8MHZ
M =4
N= 84
P= 2 */

#define PLL_M 4
#define PLL_N 84
#define PLL_P 0 //2


/*
 *
 * f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 * f(PLL general clock output) = f(VCO clock) / PLLP
 * 84MHZ
*/

void Init_Clock_HSI(void);

void Init_Clock_HSE(void);


#endif /* INC_CLOCK_CONFIG_H_ */
