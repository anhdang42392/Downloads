files := file1 file2 
a := one two
b := 'one two \n'
x := dude
z := $(CURDIR)
NEXTDIR := $(z)/build 
SECONDDIR := $(NEXTDIR)/src 
CSRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(CSRC))

include ~/Downloads/GNUmakefile

blah: blah.o  
	gcc blah.o -o blah 

blah.o: blah.c 
	gcc -c blah.c -o blah.o 

blah.c: 
	echo "int main() {return 0;}" > blah.c 

some_file: other_file $(files)
	@echo "This will always run, and runs second"
	@echo "Look this variable: " $(files)
	touch some_file

other_file: 
	echo "This will always run first"



file1: 
	touch file1

file2: 
	touch file2

all: 
	printf '$a\n'
	printf $b
	@echo $(x)
	echo ${x}
	echo $x 
	@echo $(z)
	@echo $(NEXTDIR)
	@echo $(SECONDDIR)
	@mkdir -p $(NEXTDIR)
	@make --directory=$(SECONDDIR)
	@echo $(CSRC)
	@echo $(OBJ)
	@ld -relocatable *.o -o main

clean: 
	rm -f file1 file2 some_file file hello.o main.o blah.o blah 

	

