CC = avr-gcc
SRC = main.c DIO_prog.c LCD_prog.c
CFLAGS = -mmcu=atmega32 -I . -O
OUT = main.o

PRO = avrdude

%.i :%.c
	$(CC) $< $(CFLAGS) -E -o $@

%.asm : %.i
	$(CC) $< $(CFLAGS) -S -o $@

%.o : %.c
	$(CC) $< $(CFLAGS) -o $@


.PHONY : build
build:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

.PHONY : load
load: clean build
	$(PRO) -p atmega32 -c usbasp -U flash:w:$(OUT)

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

