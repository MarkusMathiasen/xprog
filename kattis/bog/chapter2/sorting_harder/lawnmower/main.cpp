#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; double w;
	while (scanf("%d%d%lf", &n, &m, &w), m && n && w) {
		bool possible = true;
		vector<double> A(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%lf", &A[i]);
		sort(A.begin(), A.end());
		possible &= A.front()-w/2 <= 0.0;
		possible &= A.back()+w/2 >= 75.0;
		for (int i = 1; i < n; i++)
			possible &= A[i] - A[i-1] <= w;
		A.assign(m, 0);
		for (int i = 0; i < m; i++)
			scanf("%lf", &A[i]);
		sort(A.begin(), A.end());
		possible &= A.front()-w/2 <= 0.0;
		possible &= A.back()+w/2 >= 100.0;
		for (int i = 1; i < m; i++)
			possible &= A[i] - A[i-1] <= w;
		printf(possible ? "YES\n" : "NO\n");
	}
}
