/*
 * LED.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */

#ifndef LED_H_
#define LED_H_
#define ON 1
#define OFF 0
#include "../MCAL/dio.h"
#include "../MCAL/timer.h"
void LED_init();
void LED_on();
void LED_off();
void LED_toggle();
void LED_blink();

#endif /* LED_H_ */
