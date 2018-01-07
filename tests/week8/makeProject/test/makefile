SRC = main.c func.c
CC = gcc
INCLUDES = ./ -I ../
CFLAGS = -I $(INCLUDES)

%.o : $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)
