#include <bits/stdc++.h>

using namespace std;

double c;

int main() {
	scanf("%lf", &c);
	double low = 0;
	double high = 1e5;
	while (low + 1e-8 < high) {
		double mid = (low + high) / 2;
		if (mid*mid + sqrt(mid) < c)
			low = mid;
		else
			high = mid;
	}
	printf("%f\n", low);
}
