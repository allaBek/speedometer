#ifndef __SPEEDOMETER_H__

#include <inttypes.h>







uint16_t adc_read(uint8_t ch);
void adc_init();

void print_lcd(char* msg, int size, uint8_t x, uint8_t y);
void print_lcd_int(uint16_t msg, int size, uint8_t x, uint8_t y);





#endif