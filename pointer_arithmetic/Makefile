CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined -lm
TARGET = pointer_arithmetic
SRC = $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SRC)
	${CC} ${CFLAGS} -o $@ $^

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
