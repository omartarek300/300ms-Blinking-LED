/*
 * dio.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */
#include "dio.h"
void DIO_init(uint8_t Port_name, uint8_t value )
{
	switch(Port_name)
	{
		case PA:
		{
			DDRA |= value;
		}
		break;
		case PB:
		{
			DDRB |= value;
		}
		break;
		case PC:
		{
			DDRC |= value;
		}
		break;
		case PD:
		{
			DDRD |= value;
		}
		break;
	}
}
void DIO_set(uint8_t Port_name, uint8_t value)
{
	switch(Port_name)
	{
		case PA:
		{
			PORTA |= value;
		}
		break;
		case PB:
		{
			PORTA |= value;
		}
		break;
		case PC:
		{
			PORTA |= value;
		}
		break;
		case PD:
		{
			PORTA |= value;
		}
		break;
	}
}
void DIO_reset(uint8_t Port_name, uint8_t value)
{
	switch(Port_name)
	{
		case PA:
		{
			PORTA = PORTA & (~value);
		}
		break;
		case PB:
		{
			PORTB = PORTB & (~value);
		}
		break;
		case PC:
		{
			PORTC = PORTC & (~value);
		}
		break;
		case PD:
		{
			PORTD = PORTD & (~value);
		}
		break;
	}
}
uint8_t DIO_read(uint8_t Port_name, uint8_t value )
{
	uint8_t Data = 0;
	switch(Port_name)
	{
		case PA:
		{
			Data =  PINA & value;
		}
		break;
		case PB:
		{
			Data =  PINB & value;
		}
		break;
		case PC:
		{
			Data =  PINC & value;
		}
		break;
		case PD:
		{
			Data =  PIND & value;
		}
		break;
	}
	return Data;
}
