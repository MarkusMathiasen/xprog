#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int x, y, dx, dy;

void up() {
	printf("up\n");
	y++;
}
void down() {
	printf("down\n");
	y--;
}
void left() {
	printf("left\n");
	x--;
}
void right() {
	printf("right\n");
	x++;
}

void get_out() {
	while (x < 32 && y < 32)
		up(), right();
	while (x < 32)
		right();
	while (y < 32)
		up();
}
void push_down() {
	while (x > 0) {
		left();
		while (y > 0)
			down();
		while (y < 32)
			up();
	}
}
void push_in_right(int dx) {
	for (int i = 0; i < dx; i++)
		right();
	for (int i = 0; i < 31; i++) {
		up();
		left();
		right();
	}
	while (y > -32)
		down();
	for (int i = 0; i < dx; i++)
		left();
}

void push_in_left(int dx) {
	for (int i = 0; i < dx; i++)
		left();
	for (int i = 0; i < 31; i++) {
		up();
		right();
		left();
	}
	while (y > -32)
		down();
	for (int i = 0; i < dx; i++)
		right();
}

void push_up() {
	while (y+1 < dy)
		up();
	while (y > -32)
		down();
}

int main() {
	scanf("%d%d%d%d%d", &x, &x, &y, &dx, &dy);
	get_out();
	push_down();
	left();
	while (y > -32)
		down();
	while (x < dx)
		right();
	for (int i = 31; i > 1; i--)
		push_in_right(i),
		push_up();
	for (int i = 31; i > 1; i--)
		push_in_left(i),
		push_up();
}
