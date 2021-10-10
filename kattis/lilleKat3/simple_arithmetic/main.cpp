#include <bits/stdc++.h>

using namespace std;

long double a, b, c;

int main() {
	cin >> a >> b >> c;
	long double upper = 1e18;
	long double lower = 0;
	while (lower + 1e-8 < upper) {
		long double mid = (lower + upper) / 2;
		if (mid < a*b/c)
			lower = mid;
		else
			upper = mid;
	}
	printf("%Lf\n", lower);
}
