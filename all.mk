export BASE_DIR=${CURDIR}
export BUILD_DIR=${BASE_DIR}/build
export SRC_DIR=${BASE_DIR}/src
export CC=gcc

export MODULE1_BUILD_DIR = ${BUILD_DIR}/module1
export MODULE2_BUILD_DIR = ${BUILD_DIR}/module2

TARGET=main

MODULE1_SRC=${SRC_DIR}/module1
MODULE2_SRC = ${SRC_DIR}/module2


all: module1 module2 ${TARGET}

module1: 
	@make --directory=${MODULE1_SRC}

module2: 
	@make --directory=${MODULE2_SRC}

main:
	${CC} -c -o ${BUILD_DIR}/${TARGET}.o ${SRC_DIR}/main.c
	@ld -relocatable ${MODULE1_BUILD_DIR}/*.o ${MODULE2_BUILD_DIR}/*.o ${BUILD_DIR}/${TARGET}.o -o ${TARGET}
	${CC} ${MODULE1_BUILD_DIR}/*.o ${MODULE2_BUILD_DIR}/*.o ${BUILD_DIR}/${TARGET}.o -o ${TARGET}
