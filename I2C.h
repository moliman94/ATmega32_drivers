/*
 * I2C.h
 *
 * Created: 29-Apr-20 7:26:08 PM
 *  Author: Mohamed Soliman
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "Header.h"

// Master
void I2C_master_init(void);
void I2C_master_start();
void I2C_master_addr(uint8 addr);
void I2C_master_write(uint8 data);
void I2C_master_stop(void);

// Slave
void I2C_slave_Init(uint8 My_Add);
uint8 I2C_slave_avialable();
uint8 I2C_slave_read(void);

#endif /* I2C_H_ */