build:
	avr-gcc -Os -mmcu=atmega328p -c uart.c adc.c test.c
	avr-gcc -mmcu=atmega328p -Wl,-u,vfprintf -lprintf_flt uart.o adc.o test.o -o test.elf
	avr-objcopy -O ihex -R .eeprom test.elf test.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/cu.usbmodem1421 -b 115200 -U flash:w:test.hex
clean:
	rm *.elf
	rm *.o
	rm *.hex
