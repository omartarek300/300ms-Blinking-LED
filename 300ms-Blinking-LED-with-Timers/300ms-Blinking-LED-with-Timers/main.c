/*
 * 300ms_Blinking_LED.c
 *
 * Created: 9/7/2021 2:22:07 AM
 * Author : Omar
 */ 
#include "ECUAL/LED.h"
int main(void)
{
			
    LED_init(PA,pin1);
    while (1) 
    {
		LED_blink();
    }
}

