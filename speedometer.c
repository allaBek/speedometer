#include "speedometer.h"

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>


void adc_init()
{
    //initialize adc
   ADMUX |= (1 << REFS0); //reference voltage on AVCC
   ADCSRA |= (1 << ADPS2) |(1 << ADPS1) | (1 << ADPS0); //ADC clock prescaler /128
   ADCSRA |= (1 << ADEN); //enables the ADC
   ADCSRA |= (1 << ADSC); //start ADC conversion
 }
uint16_t adc_read(uint8_t ch)
{
  // select the corresponding channel 0~7
  // ANDing with ’7′ will always keep the value
  // of ‘ch’ between 0 and 7
  ch &= 0b00000111;  // AND operation with 7
  ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
  // start single convertion
  // write ’1′ to ADSC
  ADCSRA |= (1<<ADSC);
 
  // wait for conversion to complete
  // ADSC becomes ’0′ again
  // till then, run loop continuously
  while(ADCSRA & (1<<ADSC));
 
  return (ADC);
}
void print_lcd(char* msg, int size,uint8_t clr, uint8_t x, uint8_t y)
{
   if(clr == 1)
   {nokia_lcd_clear();}
   nokia_lcd_set_cursor(x,y);
   nokia_lcd_write_string(msg,size);
   nokia_lcd_render();
}