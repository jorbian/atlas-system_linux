CC := gcc
CFLAGS := -Werror -Wall -Wextra -pedantic -std=gnu89
SRC :=  $(shell find $(SRC_PATH) -type f -name '*.c')
HEAD := hls.h
OBJ := $(SRC: %.c = %.o)
NAME := hls

all: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

debug: $(OBJ)
	$(CC) $(CFLAGS) $^ -g -o $(NAME)-debug

release: all debug

.PHONY: debug release

$(SRC): $(HEAD)
