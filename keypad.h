/*
 * keypad.h
 *
 * Created: 31-Mar-20 12:05:02 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Header.h"

#define KEYPAD_COL_DIR DDRD
#define KEYPAD_COL_PORT PORTD
#define KEYPAD_COL_PIN PIND
#define KEYPAD_ROW_DIR DDRB
#define KEYPAD_ROW_PORT PORTB
#define C1 2
#define C2 3
#define C3 4
#define C4 5
#define R1 4
#define R2 5
#define R3 6
#define R4 7

void keypad_init();
uint8 keypad_read();

#endif /* KEYPAD_H_ */