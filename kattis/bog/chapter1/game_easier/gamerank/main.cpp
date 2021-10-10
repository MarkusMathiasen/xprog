#include <bits/stdc++.h>
using namespace std;

int stars = 0;
int ran = 25;
int streak = 0;

int req(int ran);

void lose() {
	streak = 0;
	if (ran > 20)
		return;
	if (stars == 0) {
		if (ran == 20)
			return;
		ran++;
		stars = req(ran)-1;
	}
	else
		stars--;
}
void win() {
	streak++;
	stars++;
	if (streak >= 3 && ran > 5)
		stars++;
	if (stars > req(ran)) {
		stars = stars-req(ran);
		ran--;
	}
}

int req(int ran) {
	if (ran > 20)
		return 2;
	if (ran > 15)
		return 3;
	if (ran > 10)
		return 4;
	return 5;
}

int main() {
	char c;
	while (scanf("%c", &c), c != '\n') {
		if (ran == 0)
			continue;
		if (c == 'W')
			win();
		else
			lose();
		//printf("rank: %d\nstars:%d\n\n", ran, stars);
	}
	if (ran == 0)
		printf("Legend\n");
	else
		printf("%d\n", ran);
}
