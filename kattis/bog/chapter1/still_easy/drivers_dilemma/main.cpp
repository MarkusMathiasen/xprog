#include <bits/stdc++.h>
using namespace std;

int speed[6];
double fuel[6];
double C, X, M;

bool pos(int i) {
	double used = 0;
	used += M/fuel[i];
	double tim = M/speed[i];
	used += tim*X;
	return used <= C/2;
}

int main() {
	scanf("%lf%lf%lf", &C, &X, &M);
	for (int i = 0; i < 6; i++)
		scanf("%d%lf", speed+i, fuel+i);
	for (int i = 5; i >= 0; i--) {
		if (pos(i)) {
			printf("YES %d\n", speed[i]);
			return 0;
		}
	}
	printf("NO\n");
}
