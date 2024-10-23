export NOW_DIR = $(CURDIR)#Downloads/hello
export BUILD = $(NOW_DIR)/build#Downloads/hello/build
export BUILD_SRC = $(BUILD)/src#Downloads/hello/build/src
export SRCDIR = $(NOW_DIR)/src#Downloads/hello/src
export CC = gcc 

export BUILD_MODULE1 = $(BUILD_SRC)/module1#Downloads/hello/build/src/module1
export BUILD_MODULE2 = $(BUILD_SRC)/module2#Downloads/hello/build/src/module2

export SRC_MODULE1 = $(SRCDIR)/module1  #Downloads/hello/src/module1
export SRC_MODULE2 = $(SRCDIR)/module2   #Downloads/hello/src/module2 


include ~/Downloads/hello/src/Makefile
include ~/Downloads/hello/src/module1/Makefile
include ~/Downloads/hello/src/module2/Makefile




all:
	$(CC) -c $(SRCDIR)/main.c -o $(BUILD_SRC)/main.o 
	$(CC) $(BUILD_MODULE1)/*.o $(BUILD_MODULE2)/*.o $(BUILD_SRC)/*.o -o $(BUILD)/main


