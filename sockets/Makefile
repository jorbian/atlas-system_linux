CC ?= gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
COBJFLAGS := $(CFLAGS) -c
INC_PATH := ./inc
LIB_SRC_DIR := ./src/socketlib
LIB_SRCS := $(wildcard $(LIB_SRC_DIR)/*.c)
LIB_OBJS := $(LIB_SRCS:.c=.o)

todo_api_0: todo_api_0.o $(LIB_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

todo_api_0.o: todo_api_0.c
	$(CC) $(COBJFLAGS) -I$(INC_PATH) -o $@ $<

todo_api_1: todo_api_1.o $(LIB_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

todo_api_1.o: todo_api_1.c
	$(CC) $(COBJFLAGS) -I$(INC_PATH) -o $@ $<

todo_api_2: todo_api_2.o $(LIB_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

todo_api_2.o: todo_api_2.c
	$(CC) $(COBJFLAGS) -I$(INC_PATH) -o $@ $<

$(LIB_SRC_DIR)/%.o: $(LIB_SRC_DIR)/%.c
	$(CC) $(COBJFLAGS) -I$(INC_PATH) -o $@ $<
