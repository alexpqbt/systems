CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined

all: mywc

mywc: mywc.c
	$(CC) $(CFLAGS) -o $@ $<

test: mywc
	./run_test.sh	

clean:
	rm -f mywc
