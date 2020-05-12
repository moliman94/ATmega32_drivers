/*
 * LCD.h
 *
 * Created: 25-Mar-20 1:33:33 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "Header.h"

#define RS PA1
#define EN PA2
#define D4 PA3
#define D5 PA4
#define D6 PA5
#define D7 PA6
#define shift (7-D7)      
#define LCD_DIRR DDRA
#define LCD_PORTR PORTA

void LCD_init();
void LCD_send_command(uint8 cmd);
void LCD_print_char(uint8 ch);
void LCD_print_string(char *str);
void LCD_print_num(sint16 num);
void LCD_print_num_2_dig(uint8 num);
void LCD_send_pulse();
void LCD_goto_xy(uint8 x, uint8 y);


#endif /* LCD_H_ */