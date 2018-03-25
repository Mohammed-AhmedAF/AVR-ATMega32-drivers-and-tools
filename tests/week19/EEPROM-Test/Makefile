MAIN = main.c
CC = avr-gcc
SRC = $(MAIN) DIO_prog.c LCD_prog.c EEPROM_prog.c TWI_prog.c
CFLAGS = -mmcu=atmega32 -I . -O3

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

.PHONY : load
load: clean generate_ctags build
	$(PRO) -p atmega32 -c usbasp -U flash:w:main.o
	rm -f *.o *.i

.PHONY : flash
flash :
	$(PRO) -p atmega32 -c usbasp -U flash:w:main.o

.PHONY : convert
convert: clean
	unix2dos *

.PHONY : reconvert
reconvert : clean
	dos2unix * 
.PHONY : clean
clean:
	rm -f *.o *.i

