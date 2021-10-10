#include <bits/stdc++.h>
using namespace std;

int main() {
	int y; scanf("%d", &y);
	vector<bool> years(10001, 0);
	int year = 2018;
	int month = 3;
	while (year < y) {
		year += 2;
		month = (month+2)%12;
		year += month == 1;
	}
	if (y > 10000)
		throw y;
	printf(year == y ? "yes\n" : "no\n");
}
