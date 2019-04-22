#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "speedometer.h"

#include "nokia5110.h"
uint16_t layout = 0;
void gui (uint16_t buttons, uint16_t speed, uint16_t distance, int16_t temperature)
{
   //layout 0: main layout, has speed
   nokia_lcd_clear();
   switch (layout) {
   case 0: 
       nokia_lcd_set_cursor(30,0);
       nokia_lcd_write_string("Speed",1);
       print_lcd_int(speed, 3, 30, 20);
      if(buttons < 700 && buttons > 600)
      {
	 if(layout == 0)
	 { layout = 2;}
	 else
	 {layout--;}
      }	 
      else if(buttons < 900 && buttons > 800)
      {
	 if(layout == 2)
	 { layout = 0;}
	 else
	 {layout++;}
      }	 
      break;
  case 1:
       nokia_lcd_set_cursor(25,0);
       nokia_lcd_write_string("Distance",1);
       print_lcd_int(distance, 3, 30, 20);
     if(buttons < 700 && buttons > 600)
      {
	 if(layout == 0)
	 { layout = 2;}
	 else
	 {layout--;}
      }	 
      else if(buttons < 900 && buttons > 800)
      {
	 if(layout == 2)
	 { layout = 0;}
	 else
	 {layout++;}
      }	 
      break;
  case 2:
       nokia_lcd_set_cursor(15,0);
       nokia_lcd_write_string("Temperature",1);
       print_lcd_int(temperature, 3, 30, 20);
 if(buttons < 700 && buttons > 600)
      {
	 if(layout == 0)
	 { layout = 2;}
	 else
	 {layout--;}
      }	 
      else if(buttons < 900 && buttons > 800)
      {
	 if(layout == 2)
	 { layout = 0;}
	 else
	 {layout++;}
      }	 
      break;
  
  
   }
     
   
   
}

int main(void)
{
   
   //DDRD = 0xff;
    adc_init();
   nokia_lcd_init();
   layout = 1;
    while(1) {
      // print_lcd(char* msg, int size,uint8_t clr, uint8_t x, uint8_t y)
          uint16_t buttons=adc_read(3);
       gui(buttons,30, 12, 35);
       _delay_ms(10);
     }
}