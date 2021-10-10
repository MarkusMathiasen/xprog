#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> A; A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf(" %d", &A[i]);
	sort(A.begin(), A.end());
	long long res = 1;
	for (int k : A) {
		if (k > res) {
			break;
		}
		res += k;
	}
	printf("%lld\n", res);
}
