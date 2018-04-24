/*
    Thanks to: http://maxembedded.com/2011/06/the-adc-of-the-avr/
*/
#include <avr/io.h>

void adc_init() {
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
 
uint16_t adc_read(uint8_t ch) {
    ch &= 0b00000111;
    ADMUX = (ADMUX & 0xF8)|ch;
    ADCSRA |= (1<<ADSC);
 
    while(ADCSRA & (1<<ADSC));
 
    return (ADC);
}