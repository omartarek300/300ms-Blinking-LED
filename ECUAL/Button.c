/*
 * Button.c
 *
 * Created: 9/6/2021 3:22:43 AM
 *  Author: Omar
 */ 
#include "Button.h"
void Button_init()
{
	DIO_init(PC, 0X00);
}
uint8_t Button_read()
{
	return DIO_read(PC, 0X01);
}