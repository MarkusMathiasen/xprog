#include <bits/stdc++.h>
using namespace std;

int N, M, S;
int m = 0, s = 0;

int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &M, &S);
		m += M, s += S;
	}
	double res = (double)s / (60 * m);
	if (res <= 1)
		printf("measurement error\n");
	else
		printf("%.9lf\n", res);
}
