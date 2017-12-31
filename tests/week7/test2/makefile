CFLAGS = -mmcu=atmega32 -DF_CPU=8000000 -O
CC = avr-gcc

%.o : %.c
	$(CC) -o $(FN) $^ $(CFLAGS)
	
flash :
	avrdude -p m32 -c usbasp -U flash:w:$(FN)

clean :
	rm *.o
