CC := gcc
CFLAGS := -std=c2x \
	  -Wall \
	  -Wextra \
	  -Wpedantic \
	  -Wshadow \
	  -Wconversion \
	  -Wnull-dereference \
	  -Wdouble-promotion \
	  -Wformat=2 \
	  -g -O0 \
	  -fsanitize=address,undefined \
	  -MMD -MP
LDFLAGS := -fsanitize=address,undefined

PROGRAMM := main
BUILD_DIR := build
TARGET := $(BUILD_DIR)/$(PROGRAMM)


SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

.PHONY: clean build all run

build: clean $(TARGET)

all: clean $(TARGET) run

$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@echo $(TARGET)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	@rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)
