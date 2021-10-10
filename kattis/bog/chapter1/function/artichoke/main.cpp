#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, a, b, c, d, n;
	cin >> p >> a >> b >> c >> d >> n;
	double big = p*(sin(a+b)+cos(c+d)+2);
	double res = 0;
	for (int i = 1; i <= n; i++) {
		double x = p*(sin(a*i+b)+cos(c*i+d)+2);
		res = max(res, big-x);
		big = max(big, x);
	}
	printf("%.6f\n", res);
}
