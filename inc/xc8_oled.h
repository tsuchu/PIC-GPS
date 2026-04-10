#ifndef __OLED_H
#define __OLED_H

#define OLED_CLEAR_DISP  0x01
#define OLED_RETRN_HOME  0x02
#define OLED_GO_TO_LINE2 0xC0

void oled_write16(uint16_t data);
void oled_writeCMD(unsigned char cmd);
void oled_writeSTR(const char* str);

#endif