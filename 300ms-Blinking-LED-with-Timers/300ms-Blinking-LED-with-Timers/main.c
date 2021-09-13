/*
 * 300ms_Blinking_LED.c
 *
 * Created: 9/7/2021 2:22:07 AM
 * Author : Omar
 */ 
#include "ECUAL/LED.h"
#define counts_num 293
int main(void)
{			
    LED_init(PA,pin1);
	config conf = {timer1, compare, f_cpu_clk_1024, counts_num}; // initialize timer
	Timer_init(&conf);
    while (1) 
    {
		LED_blink();
    }
}

