CC ?= gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
COBJFLAGS := $(CFLAGS) -c
INC_PATH := ./inc
LIB_SRC_DIR := ./src/socketlib
LIB_SRCS := $(wildcard $(LIB_SRC_DIR)/*.c)
LIB_OBJS := $(LIB_SRCS:.c=.o)

todo_api_0: task4.o shared.o
	$(CC) $(CFLAGS) -o todo_api_0 task4.o socketlib.o

task4.o: task4.c socketlib.h
	$(CC) $(CFLAGS) -c 4-main.c

socketlib.o: socketlib.c socketlib.h
	$(CC) $(CFLAGS) -c shared.c

