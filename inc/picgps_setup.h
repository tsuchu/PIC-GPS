#ifndef SETUP
#define SETUP

#pragma config RSTOSC = HFINTOSC_64MHZ
#pragma config LVP = ON
#pragma config CSWEN = ON
#define _XTAL_FREQ 64000000

#include "pic_pins.h"

void pic_setup(void);
void spi_init(void);
void adc_init(void);
void pwm_init(void);
void timer_init(void);
void uart_init(void);
void i2c_init(void);
void init_all(void);
// sqrt function to test the tft module
float sqrt(float n);
#endif