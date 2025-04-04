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
	  -fsanitize=address,undefined
LDFLAGS := -fsanitize=address,undefined

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,build/%.o,$(SRC))
TARGET := build/main

.PHONY: all clean run debug

all: $(TARGET)

# Link step
$(TARGET): $(OBJ)
	@mkdir -p build
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile each .c file to build/*.o
build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf build

run:
	./build/main

debug:
	ASAN_OPTIONS=detect_leaks=0 gdb ./build/main
