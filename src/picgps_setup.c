#include <xc.h>
#include "../inc/picgps_setup.h"

void pic_setup() {
    OSCCON1bits.NDIV = 0x00;
    OSCTUNEbits.TUN  = 0x00;
}

void spi_init(void) {
    LATB &= ~(SPI_SCK_PIN | SPI_SDO_PIN | TFT_DC_PIN | TFT_nRST_PIN | TFT_CS_PIN);
    SPI1CON0bits.EN   = 0;
    SPI1CON1bits.CKE  = 0;
    SPI1CON1bits.CKP  = 0;
    SPI1CON1bits.SSP  = 1;
    SPI1CON1bits.SDOP = 0;
    
    SPI1BAUD = 3332; // aim for 9600 baud rate
    SPI1CON0bits.EN = 1;
}

void adc_init(void) {
    
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
    adc_init();
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
    return root;
}