CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -O2 -g -Iinclude
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

NAME = $(notdir $(CURDIR))
TARGET = build/$(NAME)

SOURCE_FILES = $(wildcard src/*.c)
OBJECT_FILES = $(patsubst src/%.c, build/%.o, $(SOURCE_FILES))

all: $(TARGET)


$(TARGET): $(OBJECT_FILES) | build
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $@ $(LIBS)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

run: all
	./$(TARGET)
clean:
	rm -rf build
compile: clean all run
.PHONY: all run clean