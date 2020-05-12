/*
 * keypad.c
 *
 * Created: 31-Mar-20 12:04:45 AM
 *  Author: Mohamed Soliman
 */ 

#include "keypad.h"
#define INTERNAL_PULLUP 1


uint8 keypad_matrix[4][4] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
   	{'1', '2', '3', '-'},
	{'c', '0', '=', '+'}
};


void keypad_init()
{
	KEYPAD_COL_DIR &= ~((1<<C1)|(1<<C2)|(1<<C3)|(1<<C4));
	KEYPAD_ROW_DIR |= (1<<R1)|(1<<R2)|(1<<R3)|(1<<R4);
	
#if INTERNAL_PULLUP
	KEYPAD_COL_PORT |= (1<<C1)|(1<<C2)|(1<<C3)|(1<<C4);    //activate internal pull-up resistor
#endif
}

uint8 keypad_read()
{
	uint8 i;
	KEYPAD_ROW_PORT |= (1<<R1)|(1<<R2)|(1<<R3)|(1<<R4);
	for(i=R1; i<=R4; i++)
	{
		CLRBIT(KEYPAD_ROW_PORT, i);
		_delay_ms(1);
		if(READBIT(KEYPAD_COL_PIN, C1) == 0) return keypad_matrix[i-R1][0];
		else if(READBIT(KEYPAD_COL_PIN, C2) == 0) return keypad_matrix[i-R1][1];
		else if(READBIT(KEYPAD_COL_PIN, C3) == 0) return keypad_matrix[i-R1][2];
		else if(READBIT(KEYPAD_COL_PIN, C4) == 0) return keypad_matrix[i-R1][3];
		_delay_ms(1);
		SETBIT(KEYPAD_ROW_PORT, i);
	}

	return 0;
}