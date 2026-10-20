#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	size_t len, cap;
} Vec;

void vec_init(Vec *v) {
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}

int vec_push(Vec *v, int data) {
	if (v->len == v->cap) {
		size_t new_cap = v->cap == 0 ? 4 : v->cap * 2;	
		int *new_data = realloc(v->data, sizeof(int) * new_cap);
		if (new_data == NULL) {
			return -1;
		}
		v->data = new_data;
		v->cap = new_cap;
	}

	v->data[v->len++] = data;
	return 0;
}

int vec_pop(Vec *v, int *out) {
	if (v->len == 0) return -1;
	int x = v->data[--v->len];
	if (out) *out = x;
	return 0;
}

void vec_free(Vec *v) {
	free(v->data);
	vec_init(v);
}

void print_vec(const Vec *v) {
	for (size_t i = 0; i < v->len; i++) {
		printf("[%zu]: %d\n", i, v->data[i]);
	}
}

int main(void) {
	Vec v = {0};
	Vec *p = &v;

	vec_init(p);

	vec_free(p);
}
