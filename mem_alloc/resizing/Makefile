CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -O0 -g -fsanitize=address,undefined
TARGET = resizing 
SRC = $(wildcard *.c)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

a.out: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: a.out
	./a.out

clean:
	rm -f $(TARGET) *.out

