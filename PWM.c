/*
 * PWM.c
 * PWM driver for ATmega32 on Timer1 16-bit
 * 
 * Created: 19-Apr-20 4:20:16 PM
 *  Author: Mohamed Soliman
 */ 

#include "PWM.h"

void PWM_timer1_OC1A_init()
{
	SETBIT(DDRD, PD5);    //set OC1A pin as output
	
	//choose non inverting mode COM1A1:0 --> 0b10
	TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0));
	SETBIT(TCCR1A, COM1A1);
	
	//choose fast PWM mode, 10-bit
	TCCR1A |= (1<<WGM11) | (1<<WGM10);
	TCCR1B |= (1<<WGM12);
	
	//setting no prescaler
	TCCR1B &= ~((CS12)|(CS11)|(CS10));
	SETBIT(TCCR1B, CS10);
}

void set_duty_OC1A(uint8 duty)
{
	OCR1A = duty * 10.23;
}