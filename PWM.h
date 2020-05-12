/*
 * PWM.h
 * PWM driver for ATmega32 on Timer1 16-bit
 * 
 * Created: 19-Apr-20 4:20:44 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "Header.h"

void PWM_timer1_OC1A_init();
void set_duty_OC1A(uint8 duty);

#endif /* PWM_H_ */