SRC := helloMain.c \
	func.c

OBJ := $(SRC:.c=.o)

CC = gcc
CFLAGS = -g

%.o : $(SRC)
	$(CC) -o $@ $^ -I /..

clean :
	rm *.o
