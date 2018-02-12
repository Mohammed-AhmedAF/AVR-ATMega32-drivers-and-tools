CC = gcc
SRC = main.c func.c
CFLAGS = -I ..

%.o : $(SRC)
	$(CC) $(SRC) -o $@ $(CFLAGS)

%.asm : $(SRC)
	$(CC) $(SRC) -o $@ $(CFLAGS)

.phony : clean

clean :
	rm *.o

	
