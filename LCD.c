/*
 * LCD.c
 * Driver of 16x2 LCD (1602A) in 4-bit mode
 * Pins of LCD are connected to Atmega32 as follow:
 * RS --> PA1
 * EN --> PA2
 * D4 --> PA3
 * D5 --> PA4
 * D6 --> PA5
 * D7 --> PA6
 *
 * Created: 25-Mar-20 1:33:14 PM
 *  Author: Mohamed Soliman
 */ 

#include "LCD.h"

void LCD_init()
{
	LCD_DIRR |= (1<<RS)|(1<<EN)|(1<<D4)|(1<<D5)|(1<<D6)|(1<<D7);  //configure PA1 ~ PA6 pins as output
	
	LCD_send_command(0x3);  //function set: 8-bit, 1 Line 5x7 Dots
	_delay_ms(4);
	LCD_send_command(0x3);  
	_delay_ms(4);
	LCD_send_command(0x3);
	_delay_ms(4);
	
	LCD_send_command(0x2);  //enable 4-bit mode, 1 line 5x7 Dots
	LCD_send_command(0x28);
	LCD_send_command(0x08);
	LCD_send_command(0x01);
	LCD_send_command(0x06);
	LCD_send_command(0x0C);
	_delay_ms(20);
}

void LCD_send_command(uint8 cmd)
{
	CLRBIT(LCD_PORTR, RS);
	
	// send most byte
	LCD_PORTR &= ~((1<<D4)|(1<<D5)|(1<<D6)|(1<<D7));
	LCD_PORTR |= ((cmd & 0xF0) >> shift);
	LCD_send_pulse();
	
	//send least byte
	LCD_PORTR &= ~((1<<D4)|(1<<D5)|(1<<D6)|(1<<D7));
	LCD_PORTR |= (((cmd & 0x0F)<<4) >> shift);
	LCD_send_pulse();
}

void LCD_print_char(uint8 ch)
{
	SETBIT(LCD_PORTR, RS);
	
	//send most byte
	LCD_PORTR &= ~((1<<D4)|(1<<D5)|(1<<D6)|(1<<D7));
	LCD_PORTR |= ((ch & 0xF0) >> shift);
	LCD_send_pulse();
	
	//send least byte
	LCD_PORTR &= ~((1<<D4)|(1<<D5)|(1<<D6)|(1<<D7));
	LCD_PORTR |= (((ch & 0x0F)<<4) >> shift);
	LCD_send_pulse();
}

void LCD_print_string(char *str)
{
	uint8 i = 0;
	while(str[i] != '\0')
	{
		LCD_print_char(*(str+i));
		i++;
	}
}

void LCD_print_num(sint16 num)
{
	sint8 i;
	uint8 dig_arr[10] = {0};
	if (num == 0)
	{
		LCD_print_char('0');
		return;
	}
	else if(num < 0)
	{
		LCD_print_char('-');
		num = (~num) + 1;
	}
	for(i=0; num != 0; i++)
	{
		dig_arr[i] = num%10 + '0';
		num /= 10;
	}
	while(i != 0)
	{
		LCD_print_char(dig_arr[--i]);
	}
}

//Function to print two digit number only
void LCD_print_num_2_dig(uint8 num)
{
	uint8 i;
	uint8 dig_arr[2] = {0};
	if (num == 0)
	{
		LCD_print_string("00");
		return;
	}
	
	for(i=0; i<2; i++)
	{
		dig_arr[i] = num%10 + '0';
		num /= 10;
	}
	while(i != 0)
	{
		LCD_print_char(dig_arr[--i]);
	}
}

void LCD_send_pulse()
{
	SETBIT(LCD_PORTR, EN);
	_delay_ms(1);
	CLRBIT(LCD_PORTR, EN);
	_delay_ms(1);
}

void LCD_goto_xy(uint8 row, uint8 col)
{
	uint8 _1st_char_adr[] = {0x80, 0xC0};
	LCD_send_command(_1st_char_adr[row-1] + col-1);
	_delay_us(100);
}
