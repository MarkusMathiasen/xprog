#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int>& a) {
	int last = a[0];
	bool res = true;
	for (int x : a) {
		res &= last <= x;
		last = x;
	}
	return res;
}

int main() {
	int n; scanf("%d", &n);
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] < A[maxi])
			break;
		if (A[i] > A[maxi])
			maxi = i;
	}
	int mini = n-1;
	for (int i = n-1; i >= 0; i--) {
		if (A[i] > A[mini])
			break;
		if (A[i] < A[mini])
			mini = i;
	}
	vector<int> B;
	if (mini <= maxi) {
		printf("1 1\n");
		return 0;
	}
	for (int i = 0; i < maxi; i++)
		B.push_back(A[i]);
	for (int i = mini; i >= maxi; i--)
		B.push_back(A[i]);
	for (int i = mini+1; i < n; i++)
		B.push_back(A[i]);
	if (sorted(B))
		printf("%d %d\n", maxi+1, mini+1);
	else
		printf("impossible\n");
}
