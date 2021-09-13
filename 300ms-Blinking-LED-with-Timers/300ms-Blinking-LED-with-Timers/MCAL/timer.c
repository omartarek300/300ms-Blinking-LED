/*
 * timer.c
 *
 * Created: 9/7/2021 2:26:14 AM
 *  Author: Omar
 */ 
#include "timer.h"
void Timer_init(const config* conf)
{
	if(conf->timer_num == timer0)
	{
		if(conf->timer_mode == normal)
		{
			TCNT0 = 0; //set timer initial value to 0
			SETBIT(TIMSK,0); //enable overflow interrupt
			SETBIT(TCCR0,7); //set FOCO pin non_pwm mode
			switch(conf->timer_preScale)
			{
				case no_clock:
					CLRBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk:
					SETBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_8:
					CLRBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;	
				case f_cpu_clk_32:
					break;
				case f_cpu_clk_64:
					SETBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_128:
					break;	
				case f_cpu_clk_256:
					CLRBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;	
				case f_cpu_clk_1024:
					SETBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
			}
		}
		else if(conf->timer_mode == compare)
		{
			TCNT0 = 0; //set timer initial value to 0
			SETBIT(TIMSK,1); //enable compare interrupt	
			SETBIT(TCCR0,3);//set FOCO pin non_pwm mode and WGM
			SETBIT(TCCR0,7);//set FOCO pin non_pwm mode and WGM
			OCR0  = conf->ticks_num; //set the compare value
			switch(conf->timer_preScale)
			{
				case no_clock:
				CLRBIT(TCCR0,0);
				CLRBIT(TCCR0,1);
				CLRBIT(TCCR0,2);
				break;
				case f_cpu_clk:
				SETBIT(TCCR0,0);
				CLRBIT(TCCR0,1);
				CLRBIT(TCCR0,2);
				break;
				case f_cpu_clk_8:
				CLRBIT(TCCR0,0);
				SETBIT(TCCR0,1);
				CLRBIT(TCCR0,2);
				break;
				case f_cpu_clk_32:
				break;
				case f_cpu_clk_64:
				SETBIT(TCCR0,0);
				SETBIT(TCCR0,1);
				CLRBIT(TCCR0,2);
				break;
				case f_cpu_clk_128:
				break;
				case f_cpu_clk_256:
				CLRBIT(TCCR0,0);
				CLRBIT(TCCR0,1);
				SETBIT(TCCR0,2);
				break;
				case f_cpu_clk_1024:
				SETBIT(TCCR0,0);
				CLRBIT(TCCR0,1);
				SETBIT(TCCR0,2);
				break;
			}
		}
	}
	else if(conf->timer_num == timer1)
	{
		if(conf->timer_mode == normal)
		{
			TCNT1H = 0; //set timer initial value to 0
			TCNT1L = 0;
			SETBIT(TIMSK,2); //enable overflow interrupt
			SETBIT(TCCR1A,2); //non_pwm mode
			SETBIT(TCCR1A,3); //non_pwm mode
			switch(conf->timer_preScale)
			{
				case no_clock:
				CLRBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk:
				SETBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk_8:
				CLRBIT(TCCR1B,0);
				SETBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk_32:
				break;
				case f_cpu_clk_64:
				SETBIT(TCCR1B,0);
				SETBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk_128:
				break;
				case f_cpu_clk_256:
				CLRBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				SETBIT(TCCR1B,2);
				break;
				case f_cpu_clk_1024:
				SETBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				SETBIT(TCCR1B,2);
				break;
			}
			
		}
		else if(conf->timer_mode == compare)
		{
			TCNT1H = 0; //set timer initial value to 0
			TCNT1L = 0;
			SETBIT(TIMSK,4); //enable compare interrupt
			SETBIT(TCCR1A,2); //non_pwm mode
			SETBIT(TCCR1A,3); //non_pwm mode
			OCR1AH = (uint8_t) (conf->ticks_num >> 8);
			OCR1AL = (uint8_t)(conf->ticks_num & (0X00FF));
			SETBIT(TCCR1B,3);
			switch(conf->timer_preScale)
			{
				case no_clock:
				CLRBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk:
				SETBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk_8:
				CLRBIT(TCCR1B,0);
				SETBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk_32:
				break;
				case f_cpu_clk_64:
				SETBIT(TCCR1B,0);
				SETBIT(TCCR1B,1);
				CLRBIT(TCCR1B,2);
				break;
				case f_cpu_clk_128:
				break;
				case f_cpu_clk_256:
				CLRBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				SETBIT(TCCR1B,2);
				break;
				case f_cpu_clk_1024:
				SETBIT(TCCR1B,0);
				CLRBIT(TCCR1B,1);
				SETBIT(TCCR1B,2);
				break;
			}
		}	
	}
	else if(conf->timer_num == timer2)
	{
		if(conf->timer_mode == normal)
		{
			TCNT2 = 0; //set timer initial value to 0
			SETBIT(TIMSK,6); //enable overflow interrupt
			SETBIT(TCCR2,7); //set FOCO pin non_pwm mode
			switch(conf->timer_preScale)
			{
				case no_clock:
					CLRBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk:
					SETBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_8:
					CLRBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_32:
					SETBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_64:
					CLRBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
				case f_cpu_clk_128:
					SETBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
				case f_cpu_clk_256:
					CLRBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
				case f_cpu_clk_1024:
					SETBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
			}	
		}
		else if(conf->timer_mode == compare)
		{
			TCNT2 = 0; //set timer initial value to 0
			SETBIT(TIMSK,7); //enable compare interrupt
			SETBIT(TCCR2,3);//set FOCO pin non_pwm mode and WGM
			SETBIT(TCCR2,7);//set FOCO pin non_pwm mode and WGM
			OCR2  = conf->ticks_num; //set the compare value
			switch(conf->timer_preScale)
			{
				case no_clock:
					CLRBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk:
					SETBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_8:
					CLRBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_32:
					SETBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					CLRBIT(TCCR0,2);
					break;
				case f_cpu_clk_64:
					CLRBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
				case f_cpu_clk_128:
					SETBIT(TCCR0,0);
					CLRBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
				case f_cpu_clk_256:
					CLRBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
				case f_cpu_clk_1024:
					SETBIT(TCCR0,0);
					SETBIT(TCCR0,1);
					SETBIT(TCCR0,2);
					break;
			}
		}
	}
}