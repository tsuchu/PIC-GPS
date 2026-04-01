#pragma once

#pragma config RSTOSC = HFINTOSC_64MHZ
#pragma config WDTEN = OFF
#pragma config MCLRE = ON
#pragma config LVP = ON
#pragma config CSWEN = ON
#define _XTAL_FREQ 64000000

void pic18f47q84_setup() {
    OSCCON1bits.NDIV = 0x00;
    OSCTUNEbits.TUN  = 0x00;
}