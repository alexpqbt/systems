CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined
SRC = $(wildcard *.c)
TARGET = basics

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

a.out: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: a.out
	./$^

clean:
	rm -f $(TARGET) a.out
