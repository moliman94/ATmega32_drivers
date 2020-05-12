/*
 * seven_seg.c
 *
 * Driver for multiplexed two digits 7seg common cathode
 * Pin connections:
 * A ------> PA1
 * B ------> PA2
 * C ------> PA3
 * D ------> PA4
 * E ------> PA5
 * F ------> PA6
 * G ------> PA7
 * DOT ----> PB0
 * COM1 ---> PC6
 * COM2 ---> PC7
 *
 * Created: 22-Apr-20 7:28:24 PM
 *  Author: Mohamed Soliman
 */ 

#include "seven_seg.h"

void sev_seg_init()
{
	DDRA |= (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G);
	DDRB |= (1<<DOT);
	DDRC |= (1<<COM1)|(1<<COM2);
}

void sev_seg_print(uint8 value)
{	
	CLRBIT(PORTC, COM1);
	SETBIT(PORTC, COM2);
	uint8 _2nd_digit = value/10;
	print_digit(_2nd_digit);
	_delay_ms(1);
	
	CLRBIT(PORTC, COM2);
	SETBIT(PORTC, COM1);
	uint8 _1st_digit = value%10;
	print_digit(_1st_digit);
	_delay_ms(1);
}

void print_digit(uint8 digit)
{
	switch(digit)
	{
		case 0:
		PORTA |= (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F);
		PORTA &= ~(1<<G);
		break;
		
		case 1:
		PORTA |= (1<<B)|(1<<C);
		PORTA &= ~((1<<G)|(1<<A)|(1<<F)|(1<<E)|(1<<D));
		break;
		
		case 2:
		PORTA |= (1<<A)|(1<<B)|(1<<G)|(1<<D)|(1<<E);
		PORTA &= ~((1<<C)|(1<<F));
		break;
		
		case 3:
		PORTA |= (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<G);
		PORTA &= ~((1<<F)|(1<<E));
		break;
		
		case 4:
		PORTA |= (1<<F)|(1<<G)|(1<<B)|(1<<C);
		PORTA &= ~((1<<A)|(1<<E)|(1<<D));
		break;
		
		case 5:
		PORTA |= (1<<A)|(1<<F)|(1<<G)|(1<<C)|(1<<D);
		PORTA &= ~((1<<B)|(1<<E));
		break;
		
		case 6:
		PORTA |= (1<<A)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G);
		PORTA &= ~(1<<B);
		break;
		
		case 7:
		PORTA |= (1<<A)|(1<<B)|(1<<C);
		PORTA &= ~((1<<G)|(1<<D)|(1<<E)|(1<<F));
		break;
		
		case 8:
		PORTA |= (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G);
		break;
		
		case 9:
		PORTA |= (1<<A)|(1<<C)|(1<<D)|(1<<B)|(1<<F)|(1<<G);
		PORTA &= ~(1<<E);
		break;
	}
}