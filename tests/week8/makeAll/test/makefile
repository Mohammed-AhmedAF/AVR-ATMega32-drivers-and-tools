CC = gcc
SRC = main.c func.c
CFLAGS = -I . -w

OBJ = $(SRC:.c=.o)
%.i : %.c
	$(CC) $^ -o $@ $(CFLAGS) -E

%.s : %.i
	$(CC) $^ -o $@ $(CFLAGS) -S

#%.o : %.s
#	$(CC) $^ -o $@ $(CFLAGS) -c

.PHONY : compile-all
compile-all : $(OBJ)

.PHONY : build
build : $(SRC)
	$(CC) $^ -o sayHello.out $(CFLAGS) 
.PHONY : clean
clean :
	rm -f *.o *.i
