/*
 * Timer.h
 *
 *  Created on: Aug 6, 2026
 *      Author: USER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


#include "stdint.h"

//delay
void Timer_delay_init(uint32_t aut);
void Timer_delay(uint32_t delay);

//timer periodic
void Timer_periodit_init(uint32_t delay,uint32_t arr);


#endif /* INC_TIMER_H_ */
