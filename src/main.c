/*
 * File:   main.c
 * Author: abilbro
 *
 * Created on March 26, 2026, 11:22 AM
 */

#include <xc.h>
#include "../inc/picgps_setup.h"
#include "../inc/pic_pins.h"
#include "../inc/xc8_oled.h"

int contrast = 0;

void main(void) {
    pic_setup();
    init_all();
    
    oled_writeSTR("Location:");
    oled_writeCMD(OLED_GO_TO_LINE2);
    oled_writeSTR("Univ. Library");
    
    for (;;);
    
    return;
}
