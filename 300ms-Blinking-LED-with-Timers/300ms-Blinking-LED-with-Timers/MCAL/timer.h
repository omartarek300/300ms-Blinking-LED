/*
 * timer.h
 *
 * Created: 9/7/2021 2:26:26 AM
 *  Author: Omar
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../bit_operations.h"
#include "../MC/My_avr.h"
#include "../types.h"
/********************************** DEFINING TIMER NEW TYPES *************************************/
typedef enum
{
	timer0, timer1, timer2 
}Timers; // timers numbers
typedef enum
{
	normal, compare
}Modes; // timers modes
typedef enum
{
	no_clock, f_cpu_clk, f_cpu_clk_8, f_cpu_clk_32, f_cpu_clk_128, f_cpu_clk_64, f_cpu_clk_256, f_cpu_clk_1024
}pre_scaler; // prescalers
typedef struct  
{
	Timers timer_num;
	Modes  timer_mode;
	pre_scaler timer_preScale;
	uint32_t ticks_num;
	
}config; // timer configurations 
/************************************** FUNCTION PROTOTYPE *******************************/

/*******
	Function Description: this function is responsible for setting timer first configurations and initializations
	parameter: conf: is a structure that holds all the configurations and consists of :
						1- timer number
						2- timer mode
						3- timer prescaler
						4- timer ticks or counts
	return: none
*/
void Timer_init(const config* conf);


#endif /* TIMER_H_ */