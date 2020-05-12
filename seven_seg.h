/*
 * seven_seg.h
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
 * Created: 22-Apr-20 7:28:45 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "Header.h"

#define A PA1
#define B PA2
#define C PA3
#define D PA4
#define E PA5
#define F PA6
#define G PA7
#define DOT PB0
#define COM1 PC6
#define COM2 PC7

void sev_seg_init();
void sev_seg_print(uint8 value);
void print_digit(uint8 digit);


#endif /* SEVEN_SEG_H_ */