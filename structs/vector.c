#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? a : b)
#define max(a, b) (((a) > (b)) ? a : b)

typedef struct {
	int x, y;
} Point;

typedef struct {
	Point p1, p2;
} Rectangle;

Point create_point(int x, int y) {
	return (Point){ x, y };
}

Rectangle create_rectangle(Point a, Point b) {
	return (Rectangle){ a, b };
}

void print_point(const Point *p) {
	printf("(%d, %d)\n", p->x, p->y);
}

void print_rectangle(const Rectangle *r) {
	print_point(&r->p1);
	print_point(&r->p2);
}

double distance(Point a, Point b) {
	double x = (b.x - a.x);
	double y = (b.y - a.y);

	return sqrt(pow(x, 2) + pow(y, 2));
}

int area(const Rectangle *r) {
	double width = abs(r->p1.x - r->p2.x);
	double length = abs(r->p1.y - r->p2.y);
	
	return width * length;
}

int contains(const Rectangle *r, const Point *p) {
	int x_min = min(r->p1.x, r->p2.x);	
	int x_max = max(r->p1.x, r->p2.x);	
	int y_min = min(r->p1.y, r->p2.y);	
	int y_max = max(r->p1.y, r->p2.y);	

	return x_min <= p->x && p->x <= x_max && y_min <= p->y && p->y <= y_max;
}

void move(Point *p, int dx, int dy) {
	p->x += dx;
	p->y += dy;
}
