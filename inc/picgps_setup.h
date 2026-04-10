#ifndef SETUP
#define SETUP

#pragma config OSC = IRCIO
#pragma config WDTEN = OFF
#pragma config MCLRE = ON
#pragma config LVP = OFF
#define _XTAL_FREQ 4000000

#include "pic_pins.h"

void pic_setup(void);
void spi_init(void);
void adc_init(void);
void pwm_init(void);
void timer_init(void);
void uart_init(void);
void i2c_init(void);
void init_all(void);

#endif