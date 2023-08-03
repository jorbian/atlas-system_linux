CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -Werror -Wl,-rpath=lib -Llib -LLIEF -Iinc -g

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
	$(CXX) $(CFLAGS) $(wildcard $</*) ./lib/libLIEF.a -o$@

$(TASK_OBJ_PATH):
	mkdir -p $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(TASK_OBJ_PATH)
	$(CXX) $(CFLAGS) -c $< -o $@ -lstdc++

$(OBJ_PATH)/%: $(OBJ_PATH)/%.o
	alias gcc="g++"
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_PATH)
