CC = avr-gcc
SRC = main.c dio.c
CFLAGS = -mmcu=atmega32 -I . -O

%.i :%.c
	$(CC) $< $(CFLAGS) -E -o $@

%.asm : %.i
	$(CC) $< $(CFLAGS) -S -o $@

%.o : %.c
	$(CC) $< $(CFLAGS) -o $@


.PHONY : build
build:
	$(CC) $(SRC) $(CFLAGS) -o main.o

.PHONY : clean
clean:
	rm -f *.o *.i

