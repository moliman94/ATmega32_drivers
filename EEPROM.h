/*
 * EEPROM.h
 *
 * Created: 13-Apr-20 12:43:24 AM
 *  Author: Mohamed Soliman
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "Header.h"

void EEPROM_write(uint16 addr, uint8 data);
uint8 EEPROM_read(uint16 addr);



#endif /* EEPROM_H_ */