#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "speedometer.h"

#include "nokia5110.h"

int main(void)
{
    nokia_lcd_init();
    
   

    for (;;) {
       nokia_lcd_clear();
        nokia_lcd_write_string("123",3);
    nokia_lcd_render();
        _delay_ms(1000);
       nokia_lcd_clear();
        nokia_lcd_write_string("321",3);
    nokia_lcd_render();
         _delay_ms(1000);
    }
}