/*
THINGS I HAVE LEARNED CODING THIS:
    - reading a file
    - main function arguments
    - ctype.h
    - perror

THINGS I HAVE LEARNED OUTSIDE OF THIS: 
    - bash scripting
    - Makefile

most of these things are still iffy since
I just played around with for a little bit

lowkey i enjoyed doing this by hand lol
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *file;
    int ch;
    int line_count = 0, word_count = 0, byte_count = 0;
    int is_word;

    if (argc != 2) {
        printf("read from STDIN not implemented\n");
        return 0;
    }

    file = argv[1];
    fp = fopen(file, "r");

    if (!fp) {
        perror(file);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        byte_count++;

        if (ch == '\n') line_count++;

        if (isspace(ch)) {
            is_word = 0;
        } else if (!is_word) {
            is_word = 1;
            word_count++;
        }
    }

    if (word_count) word_count++;

    printf("%d %d %d %s\n", line_count, word_count, byte_count, file);

    fclose(fp);
    return 0;
}
