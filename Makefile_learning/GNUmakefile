.PHONY: all rule1 rule2 rule3 TEST clean build



var :="aaaaaaaa"
var3 :="bbbbbbb"

var1 = $(var)
var2 := $(var)
var3 ?= $(var)

var := "changed"
all: rule3 rule1 rule2 TEST

rule3:
	@echo "$(var1)"
	@echo "$(var2)"
	@echo "$(var3)"

rule1:
	echo "tuan anh 20"

rule2:
	@echo "hello  tuan anh"

TEST: hello.c make.c
	@echo compiling "$^ ==> $@"
	@echo $@       
	@echo $<
	@echo $^
	@echo $%
	@echo $?
	@echo $+
	@echo $|
	@echo $*
	