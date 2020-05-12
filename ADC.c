/*
 * ADC.c
 * Driver for ADC module in ATmega32
 * 
 * Created: 14-Apr-20 12:03:26 AM
 *  Author: Mohamed Soliman
 */ 

#define ADC_INTERRUPT 0

#include "ADC.h"

void ADC_init()
{
	//Make AVCC at AREF pin
	SETBIT(ADMUX, REFS0);
	
	//Enable ADC
	SETBIT(ADCSRA, ADEN);
	
#if ADC_INTERRUPT
	SETBIT(ADCSRA, ADIE);
	SETBIT(SREG, 7);
#endif

	//select the prescaler division
	//we use prescaler 128 as ADC use freq from 50khz to 200khz and the used freq of CPU is 16MHz
	//ADPS2:0 --> 0b111
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16 ADC_read(const uint8 ADC_channel)
{
	if(ADC_channel >= ADC0 && ADC_channel <= ADC7)
	{
		ADMUX &= ~((1<<MUX4)|(1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0));
		ADMUX |= ADC_channel;
		SETBIT(ADCSRA, ADSC);  //start conversion
		while(READBIT(ADCSRA, ADSC) == 1);   //wait until conversion complete
	}
	return ADC;
}