#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	vector<int> A(n, 0);
	vector<long long> B(n, -1);
	vector<set<int>> C(k, set<int>());
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]); A[i]--;
		C[A[i]].insert(i);
	}
	for (int idx : C[k-1])
		B[idx] = 0;
	for (int i = k-2; i >= 0; i--) {
		for (int idx : C[i]) {
			auto it = C[i+1].upper_bound(idx);
			int offset = 0;
			if (it == C[i+1].end())
				offset += n,
				it = C[i+1].begin();
			offset += *it - idx;
			B[idx] = ((long long)offset) + B[*it];
		}
	}
	long long res = 1e18;
	for (int i = 0; i < n; i++)
		if (A[i] == 0)
			res = min(res, B[i]);
	printf("%lld\n", res+1ll);
}
