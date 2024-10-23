.PHONY : rule1 all clean

CC := gcc
CFLAGS := -I.
INC_FILES := hello.h

%.o: %.c $(INC_FILES)
		$(CC) -I. -c -o $@ $<

rule1: hello.o main.o 
		$(CC) -o hello hello.o main.o $(CFLAGS)

clean: 
		rm -rf hello hello.o main.o