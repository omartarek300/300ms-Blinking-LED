/*
 * LED.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */
#include "LED.h"
void LED_init(uint8_t port_name,uint8_t pin_num)
{
	DIO_init(port_name, pin_num);
}
void LED_on(uint8_t port_name,uint8_t pin_num)
{
	DIO_set(port_name, pin_num);
}
void LED_off(uint8_t port_name,uint8_t pin_num)
{
	DIO_reset(port_name, pin_num);
}
void LED_toggle()
{
	volatile static uint8_t state = OFF;
	if(state == ON)
	{
		LED_off(PA,pin1);
		state = OFF;
	}
	else if(state == OFF)
	{
		LED_on(PA,pin1);
		state = ON;
	}
}
void LED_blink()
{
	//using timer1
	if(GETBIT(TIFR,bit4))
	{
		LED_toggle();
		SETBIT(TIFR,bit4); //CLEAR FLAG AFTER MATCH
	}
}



