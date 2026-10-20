CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -O0 -fsanitize=address,undefined -lm
TARGET = mem_alloc
SRC = $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SRC)
	${CC} ${CFLAGS} -o $@ $^

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
