/*
 * EEPROM.c
 *
 * Driver for EEPROM on ATmega32 micro-controller
 * It contains 1024 bytes of data EEPROM memory
 *
 * Created: 13-Apr-20 12:43:00 AM
 *  Author: Mohamed Soliman
 */ 

#include "EEPROM.h"

void EEPROM_write(uint16 addr, uint8 data)
{
	while(READBIT(EECR, EEWE) != 0);
	//while(READBIT(SPMCR, SPMEN) != 0);      //used if the software contains a Boot Loader allowing the CPU to program the Flash
	EEAR = addr;
	EEDR = data;
	SETBIT(EECR, EEMWE);
	SETBIT(EECR, EEWE);
}

uint8 EEPROM_read(uint16 addr)
{
	while(READBIT(EECR, EEWE) != 0);
	//while(READBIT(SPMCR, SPMEN) != 0);      //used if the software contains a Boot Loader allowing the CPU to program the Flash
	EEAR = addr;
	SETBIT(EECR, EERE);
	return EEDR;
}