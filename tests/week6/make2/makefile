CC = gcc
SRC = func.c main.c
CFLAGS = -I .
SWITCH = 10

ifeq ($(SWITCH), 20)
	SRC = func20.c main.c
endif

hello.o : $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm *.o
