/*
 * dio.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */

#ifndef DIO_H_
#define DIO_H_
#include "../MC/My_avr.h"
#define PA 0 //port A
#define PB 1 //port B
#define PC 2 //port C
#define PD 3 //port D
// fUNCTION TO SET THE DIRECTIONS OF THE PORT
void DIO_init(uint8_t DDR, uint8_t value );
// fUNCTION TO OUTPUT SPECIFIC VALUE ON THE PORT
void DIO_set(uint8_t port, uint8_t value);
// fUNCTION TO READ INPUT COMMING TO THE PORT
uint8_t DIO_read(uint8_t State_reg, uint8_t value );
// fUNCTION TO RESET PINS ON THE PORT
void DIO_reset(uint8_t Port_name, uint8_t value);


#endif /* DIO_H_ */
