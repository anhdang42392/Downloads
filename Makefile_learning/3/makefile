.PHONY: run1 all clean
CC := gcc
CFLAGS := -I.
INC_FILES := hello.h

run1: hello.o main.o 
	$(CC) -o hello hello.o main.o $(CFLAGS)
all: 
	$(CC) -o hello hello.c main.c $(CFLAGS)
clean: 
	rm -rf hello
