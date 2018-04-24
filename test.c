#ifndef F_CPU
#define F_CPU 16000000UL //set frequency
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "adc.h"

int main() {
  
  uart_init();
  stdout = &uart_output;

  uint16_t adc_result;
  float data;

  adc_init();

  for(;;) {
      adc_result = adc_read(0);
      data = adc_result * (5/10.24);
      printf("The temperature is: %.2lf°C\n", data);
      _delay_ms(5000);
  }
  
  return 0;
}