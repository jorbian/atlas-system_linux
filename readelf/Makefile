CC := gcc
CFLAGS := -Wall -pedantic -Wextra -Werror -std=c90 -Iinclude

ifdef DEBUG
	CFLAGS += -g
endif

OBJ_PATH := obj
SRC_PATH := src

TASK_PATH := $(wildcard $(SRC_PATH)/*)
TASK_BIN := $(notdir $(TASK_PATH))
TASK_OBJ_PATH := $(addprefix $(OBJ_PATH)/,$(TASK_BIN))

SRC_FILES := $(foreach task,$(TASK_PATH),$(wildcard $(task)/*.c))
OBJ_FILES := $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRC_FILES))

.PHONY: all clean

all: $(TASK_BIN) clean

$(TASK_BIN): %: $(OBJ_PATH)/% $(OBJ_FILES)
	$(CC) $(CFLAGS) $(wildcard $</*) -o$@

$(TASK_OBJ_PATH):
	mkdir -p $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(TASK_OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%: $(OBJ_PATH)/%.o
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_PATH)
