#
# Author: Mohammed Ahmed Abd Al-Fattah
# File: Makefile
# Purpose: This is a makefile used to compile and load AVR projects.
# The particular microcontroller I am using this file with is the 
# AVR Atmega32.
#

MAIN = main.c
CC = avr-gcc
SRC = ./HAL/*c ./MCAL/*c ./APP/*.c
MICROCNTRL = atmega32
CFLAGS = -mmcu=$(MICROCNTRL) -I . -I ./HAL -I ./MCAL -I ./APP -I ./SERVICES -O3

PRO = avrdude

%.i :%.c
	$(CC) $< $(CFLAGS) -E -o $@

%.asm : %.i
	$(CC) $< $(CFLAGS) -S -o $@

%.o : %.c
	$(CC) $< $(CFLAGS) -o $@


.PHONY : build
build:
	$(CC) $(SRC) $(CFLAGS) -o main.o

.PHONY : generate_ctags
	ctags -R

#rule to generate hex file
.PHONY : build-hex
build-hex:
	avr-objcopy -O ihex main.o .main.hex

#Added pwd to distinguish between two or more similar projects being
#developed at the moment. The pwd command itself is not shown when
#making the project, this is done by prepending the command with @
.PHONY : load
load: clean generate_ctags build
	@pwd
	$(PRO) -p $(MICROCNTRL) -c usbasp -U flash:w:main.o
	rm -f *.o *.i

.PHONY : flash
flash :
	$(PRO) -V -v -p $(MICROCNTRL) -c usbasp -U flash:w:main.o

.PHONY : convert
convert: clean
	unix2dos *

.PHONY : reconvert
reconvert : clean
	dos2unix * 

.PHONY : burn_fuses
burn_fuses:
	$(PRO) -p m32 -c usbasp -U lfuse:w:0xD4:m
	$(PRO) -p m32  -c usbasp -u hfuse:w:0xD9:m

.PHONY : clean
clean:
	rm -f *.o *.i

