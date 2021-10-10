#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int main() {
	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	dp.push_back(A[0]);
	for (int i = 1; i < n; i++) {
		if (A[i] > dp.back()) {
			dp.push_back(A[i]);
			continue;
		}
		int lower = 0;
		int upper = dp.size()-1;
		while (lower < upper) {
			int mid = (lower+upper)/2;
			if (dp[mid] > A[i])
				upper = mid;
			else if (dp[mid] < A[i])
				lower = mid+1;
		}
		dp[lower] = A[i];
	}
	cout << dp.size() << endl;
}
