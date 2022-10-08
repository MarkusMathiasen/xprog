#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int preA = 0, preB = 0;
	bool gameEnded = false;
	for (int i = 1; i <= n; i++) {
		bool error = gameEnded;
		int A, B;
		int x, y;
		scanf("%d-%d", &x, &y);
		int round = x+y;
		int drounds = round - preA - preB;
		if (((round+1)/2)%2)
			A = y, B = x;
		else
			A = x, B = y;
		if (A == preA && B == preB)
			continue;
		if (drounds < 0) {
			error = true;
		}
		if (round > 21)
			error = true;
		if (A > 11 || B > 11)
			error = true;
		if (A - preA > drounds)
			error = true;
		if (B - preB > drounds)
			error = true;
		if (error) {
			printf("error %d\n", i);
			return 0;
		}
		if (A == 11 || B == 11)
			gameEnded = true;
		preA = A;
		preB = B;
	}
	printf("ok\n");
}
