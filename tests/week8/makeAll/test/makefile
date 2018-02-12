#This makefile I made to explore make

CC = gcc
SRC = main.c func.c
CFLAGS = -I . -w

OBJ = $(SRC:.c=.o)
%.i : %.c
	$(CC) $^ -o $@ $(CFLAGS) -E

%.s : %.i
	$(CC) $^ -o $@ $(CFLAGS) -S

%.o : %.s
	$(CC) $^ -o $@ $(CFLAGS) -c


#This compile-all rule will use an implicit rule.
#As there is no recipe for that rule, GNU make will
#look for implicit rule to apply.
.PHONY : compile-all
compile-all : $(OBJ)

.PHONY : build
build : $(SRC)
	$(CC) $^ -o sayHello.out $(CFLAGS) 
.PHONY : clean
clean :
	rm -f *.o *.i *.out
