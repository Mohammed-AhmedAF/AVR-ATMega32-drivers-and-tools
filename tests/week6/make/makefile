SRC := helloMain.c \
	func.c

OBJ := $(SRC:.c=.o)

CC = gcc
CFLAGS = -g -I ../

%.o : $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm *.o
