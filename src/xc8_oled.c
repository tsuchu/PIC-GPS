#include <xc.h>
#include "../inc/xc8_oled.h"
#include "../inc/pic_pins.h"
#include "../inc/picgps_setup.h"

void oled_write16(uint16_t data) {
    LATDbits.LD0 = 0;
    _delay(80);
    for (int i = 9; i > -1; i--) {
        LATDbits.LD1 = (data & (1 << i)) ? 1 : 0;
        _delay(8);
        LATDbits.LD3 = 1;
        _delay(40);
        LATDbits.LD3 = 0;
        _delay(40);
    }
    LATDbits.LD0 = 1;
    
//    LATDbits.LD0 = 0;
//    SSPBUF = ((data >> 2) & 0xFF);
//    while (!PIR1bits.SSPIF);
//    PIR1bits.SSPIF = 0;
//    
//    SSPBUF = ((data << 6) & 0xC0);
//    while (!PIR1bits.SSPIF);
//    PIR1bits.SSPIF = 0;
//    LATDbits.LD0 = 1;
}

void oled_writeCMD(unsigned char cmd) {
    oled_write16((0b00 << 8) | cmd);
}

void oled_writeSTR(const char* str) {
    while (*str) {
        oled_write16((0b10 << 8) | *str);
        str++;
    }
}