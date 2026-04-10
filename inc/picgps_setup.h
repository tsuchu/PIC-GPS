#ifndef SETUP
#define SETUP

#pragma config OSC = IRCIO
#pragma config WDTEN = OFF
#pragma config MCLRE = ON
#pragma config LVP = OFF
#define _XTAL_FREQ 4000000

#include <xc.h>
#include "pic_pins.h"

<<<<<<< HEAD
void pic_setup(void);
void spi_init(void);
void adc_init(void);
void pwm_init(void);
void timer_init(void);
void uart_init(void);
void i2c_init(void);
void init_all(void);

#endif
=======
extern int contrast;

void pic_setup() {
    OSCCON1bits.NDIV = 0x00;
    OSCTUNEbits.TUN  = 0x00;
}

void spi_init(void) {
    LATB &= ~(SPI_SCK_PIN | SPI_SDO_PIN | TFT_DC_PIN | TFT_nRST_PIN | TFT_CS_PIN);
    SPI1CON1bits.CKE = 0;
    SPI1CON1bits.CKP = 0;
    SPI1CON1bits.FST = 1;
    SPI1CON1bits.SSP = 1;
    SPI1CON1bits.SDOP = 0;
    SPI1SSPPS = 0b011110;
    
    SPI1CLKbits.CLKSEL = 0x01;
    SPI1BAUDbits.BAUD = 276; // Aim for 115200 Baud rate
    
    SPI1CON0bits.EN = 1;
}

void adc_dma_init(void) {
    
}

void pwm_init(void) {
    
}

void timer_init(void) {
    
}

void uart_init(void) {
    
}

void i2c_init(void) {
    
}

void init_all(void) {
    spi_init();
    adc_dma_init();
    pwm_init();
    timer_init();
    uart_init();
    i2c_init();
}

// sqrt function to test the tft module
float sqrt(float n) {
    float root = n / 3, last, diff;
    if (n <= 0) return 0;
    do {
        last = root;
        root = (root + n / root) / 2;
        diff = root - last;
    } while (diff > 0.00001 || diff < -0.00001);
}
>>>>>>> origin
