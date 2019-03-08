#
# Author: Mohammed Ahmed Abd Al-Fattah
# File: Makefile
# Purpose: This is a makefile used to compile and load avr projects.
# The particular microcontroller family I am using this file with is the 
# AVR ATmega16/32 families of microcontrollers.
#

MAIN = main.c
CC = avr-gcc
SRC = $(MAIN) DIO_prog.c
MICROCONTROLLER = atmega16
CFLAGS = -mmcu=$(MICROCONTROLLER) -I . -O3

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

#Added pwd to distinguish between two or more similar projects being
#developed at the moment. The pwd command itself is not shown when
#making the project, this is done by prepending the command with @
.PHONY : load
load: clean generate_ctags build
	@pwd
	$(PRO) -p $(MICROCONTROLLER) -c usbasp -U flash:w:main.o
	rm -f *.o *.i

.PHONY : flash
flash :
	$(PRO) -p $(MICROCONTROLLER) -c usbasp -U flash:w:main.o

.PHONY : convert
convert: clean
	unix2dos *

.PHONY : reconvert
reconvert : clean
	dos2unix * 
.PHONY : clean
clean:
	rm -f *.o *.i

