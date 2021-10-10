#include <bits/stdc++.h>
using namespace std;
#define dd pair<double, double>

dd otherZero(int x) {
	double y = 31250.0/x;
	if (y <= 250)
		return dd(0, y);
	double r2 = 31250.0/(250.0-x);
	double r1 = 250 - r2;
	return dd(r1, r2);
}
dd otherwise(int r1, int r2) {
	double b1 = 31250.0/r2;
	return dd(250 - b1, 0);
}


int main() {
	int a, b; cin >> a >> b;
	if (a != 0 && b == 0) {
		dd x = otherZero(a);
		printf("%.2lf %.2lf\n", x.first, x.second);
	}
	else if (a == 0 && b != 0) {
		dd x = otherZero(b);
		printf("%.2lf %.2lf\n", x.second, x.first);
	}
	else if (a == 0 && b == 0)
		printf("125.00 125.00\n");
	else if (a == 125 && b == 125)
		printf("0.00 0.00\n");
	else if (a < b) {
		dd x = otherwise(a, b);
		printf("%.2lf %.2lf\n", x.first, x.second);
	}
	else if (a > b) {
		dd x = otherwise(b, a);
		printf("%.2lf %.2lf\n", x.second, x.first);
	}
}
