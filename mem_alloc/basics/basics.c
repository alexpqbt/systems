#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exercise1() {
	int total = 5;

	int *squares = malloc(sizeof(int) * total);

	for (int i = 0; i < total; i++)
		squares[i] = i * 2;

	for (int i = 0; i < total; i++)
		printf("%d ", squares[i]);
		
	free(squares);
}

void exercise2() {
	int total = 10;

	int *cubes = calloc(total, sizeof(int));

	for (int i = 0; i < total; i++)
		cubes[i] = i * 3;

	for (int i = 0; i < total; i++)
		printf("%d ", cubes[i]);

	free(cubes);
}

char *my_strdup(const char *s) {
	size_t length = strlen(s) + 1;	
	
	char *dst = malloc(length);

	if (dst != NULL)
		strcpy(dst, s);

	return dst;
}
void exercise3() {
	char *s = "Hello, World!";	

	char *heap_str = my_strdup(s);

	printf("%p: %s\n", (void *)s, s);
	heap_str[0] = 'J';
	printf("%p: %s\n", (void *)heap_str, heap_str);

	free(heap_str);
}

int *make_range(int start, int end) {
	if (end <= start)
		return NULL;

	int length = end - start;

	int *range = calloc(length, sizeof *range);
	if (range == NULL)
		return NULL;

	for (int i = 0; i < length; i++)
		range[i] = start + i;

	return range;
}
void exercise4() {
	int start = 5;
	int end = 15;

	int *range = make_range(start, end);

	for (int i = 0; i < (end - start); i++)
		printf("%d ", range[i]);

	free(range);
}

int main(void) {
	exercise1();
	printf("\n");
	exercise2();
	printf("\n");
	exercise3();
	printf("\n");
	exercise4();
}
