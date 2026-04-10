#include <xc.h>
#include "../inc/picgps_setup.h"
#include "../inc/xc8_oled.h"

void pic_setup() {
    OSCCON |= 0x60;
    
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
}

void spi_init(void) {
    TRISDbits.RD0 = 0;
    TRISDbits.RD1 = 0;
    TRISDbits.RD3 = 0;
    
    LATDbits.LD0 = 1;
    
//    SSPSTAT = 0xC0;
//    SSPCON  = 0x20;
    
//    PIE1bits.SSPIE = 1;
    
    __delay_ms(50);
    oled_writeCMD(0x01); // Clear Display
    __delay_ms(5);
    oled_writeCMD(0x02); // Return Home
    __delay_ms(5);
    oled_writeCMD(0x06); // Entry Mode Set
    __delay_ms(5);
    oled_writeCMD(0x38); // Function Set
    __delay_ms(5);
    oled_writeCMD(0x0C); // Display ON
    __delay_ms(5);
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