.PHONY: build clean

PATH_OUTPUT := output 
PRO_DIR := .

INCLUDE_DIRS := $(PRO_DIR)/include 
SRC_DIRS := $(PRO_DIR)/source

INCLUDE_FILES := include/sum.h 

INCLUDE_FILES := $(wildcard $(INCLUDE_DIRS)/*.h) # lay tat ca duong dan toi file .h luu vao INCLUDES_FILES


vpath %.c $(SRC_DIRS)
vpath %.h $(INCLUDE_DIRS)



build: main.o sum.o 
	gcc -c output/main.o output/sum.o -o $(PATH_OUTPUT)/app.exe
	./$(PATH_OUTPUT)/app.exe

%.o : %.c $(INCLUDE_FILES) 
	gcc -I$(INCLUDE_DIRS) -c $< -o $(PATH_OUTPUT)/$@


clean: 
	rm -rf $(PATH_OUTPUT)/*

log-%: 
	@echo $($(subst log-,,$@))