#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	map<vector<int>, int> frosh;
	int best = 0;
	while (n--) {
		vector<int> A(5, 0); scanf("%d%d%d%d%d", &A[0], &A[1], &A[2], &A[3], &A[4]);
		sort(A.begin(), A.end());
		frosh[A]++;
		best = max(best, frosh[A]);
	}
	int res = 0;
	for (auto& [k,v] : frosh)
		if (v == best)
			res += best;
	printf("%d\n", res);
}
