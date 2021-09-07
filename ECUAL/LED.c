/*
 * LED.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */
#include "LED.h"
#include "..\MC\My_avr.h"

void LED_init()
{
	DIO_init(PA, 0X01);
	config conf = {timer0, compare, f_cpu_clk_1024, 147};
	Timer_init(&conf);
}
void LED_on()
{
	DIO_set(PA,0X01);
}
void LED_off()
{
	DIO_reset(PA,0X01);
}
void LED_toggle()
{
	volatile static uint8_t state = OFF;
	if(state == ON)
	{
		LED_off();
		state = OFF;
	}
	else if(state == OFF)
	{
		LED_on();
		state = ON;
	}
}
void LED_blink()
{
	volatile static uint8_t Match_counter = 0;
	if(GETBIT(TIFR,1))
	{
		//using timer0
		SETBIT(TIFR,1); //CLEAR FLAG AFTER MATCH
		Match_counter++;
		if(Match_counter == 2)
		{
			LED_toggle();
			Match_counter = 0;
		}
	}
}



