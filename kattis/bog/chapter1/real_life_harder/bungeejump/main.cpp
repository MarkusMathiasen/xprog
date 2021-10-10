#include <bits/stdc++.h>
using namespace std;

int main() {
	double k, l, s, w;
	while (scanf("%lf%lf%lf%lf", &k, &l, &s, &w), k != 0 || l != 0 || s != 0 || w != 0) {
		double dl = max(s-l, 0.0);
		double vs = 9.81*s*2 - k*dl*dl/w;
		if (vs < 0)
			printf("Stuck in the air.\n");
		else if (sqrt(vs) <= 10)
			printf("James Bond survives.\n");
		else
			printf("Killed by the impact.\n");
	}
}
