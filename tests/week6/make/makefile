SRC := helloMain.c \
	func.c

OBJ := $(SRC:.c=.o)

CC = gcc
CFLAGS = -I . -g

%.o : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm %.o
