#include <stdio.h>

int my_strlen(char *s) {
	char *p = s;

	while (*p != '\0')
		p++;

	return p - s;
}

void *my_memcpy(void *dest, void* src, int byte_count) {
	char *s = src, *d = dest;

	while (byte_count--) {
		*d++ = *s++;
	}

	return dest;
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5, 999 };
	int b[3];

	int *p = a;

	printf("%d\n", *p);
	printf("%d\n", *(p + 1));

	for (int i = 0; i < 6; ++i) {
		printf("%d ", *(p + i));
	}
	printf("\n");

	while (*p != 999) {
		printf("%d ", *p);
		p++;
	}
	printf("\n");

	printf("%d\n", my_strlen("Hello, World!"));

	my_memcpy(b, a, 3 * sizeof(int));

	for (int i = 0; i < 3; ++i) {
		printf("%d ", *(b + i));
	}
	printf("\n");

	return 0;
}
