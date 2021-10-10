#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A(10000, 0);

bool pos(double l) {
	int res = 0;
	for (int i = 0; i < n; i++)
		res += floor(A[i]/l);
	return res >= k;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	double lower = 0;
	double upper = 1e7;
	while (lower + 1e-8 < upper) {
		double mid = (lower + upper) / 2;
		if (pos(mid))
			lower = mid;
		else
			upper = mid;
	}
	printf("%f\n", lower);
}
