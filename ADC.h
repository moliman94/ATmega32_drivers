/*
 * ADC.h
 *
 * Created: 14-Apr-20 12:03:42 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Header.h"

#define ADC0 0   //on pin 0 portA
#define ADC1 1   //on pin 1 portA
#define ADC2 2   //on pin 2 portA
#define ADC3 3   //on pin 3 portA
#define ADC4 4   //on pin 4 portA
#define ADC5 5   //on pin 5 portA
#define ADC6 6   //on pin 6 portA
#define ADC7 7   //on pin 7 portA

void ADC_init();
uint16 ADC_read(const uint8 ADC_channel);


#endif /* ADC_H_ */