#include <bits/stdc++.h>
using namespace std;

set<int> vis;

void interval(int a, int b) {
	for (int i = a; i < b; i++)
		vis.insert(i*2),
		vis.insert(i*2+1);
}

int main() {
	int n; scanf("%d", &n);
	int prev; scanf("%d%d", &prev, &prev);
	int first = prev;
	for (int i = 1; i <= n; i++) {
		int x;
		if (i == n)
			x = first;
		else
			scanf("%d%d", &x, &x);
		if (abs(x-prev) < 360-(abs(x-prev))) { // not crossing 180
			if (prev < x) { // traveling to the right
				interval(prev, x);
				vis.insert(2*x);
			}
			else { // traveling to the left
				interval(x, prev);
				vis.insert(2*prev);
			}
		}
		else if(abs(x-prev) > 360-(abs(x-prev))){ // crossing 180
			if (prev < x) { // traveling to the right
				interval(-180, prev);
				vis.insert(2*prev);
				interval(x, 180);
			}
			else { // traveling to the left
				interval(-180, x);
				vis.insert(2*x);
				interval(prev, 180);
			}
		} 
		else {
			interval(-180, 180);
		}
		prev = x;
	}
	if (vis.size() == 720l) {
		printf("yes\n");
		return 0;
	}
	int num;
	for (int i = -360; i < 360; i++) {
		if (!vis.count(i)) {
			num = i;
			break;
		}
	}
	printf("no %.1lf\n", num/2.0);
}
