#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;

int main() {
	cin >> n;
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int l = 0;
	for (int i = 1; i < n; i++) {
		if (A[i-1] > A[i])
			break;
		else if (A[i-1] < A[i])
			l = i;
	}
	int r = n-1;
	for (int i = n-2; i >= 0; i--) {
		if (A[i] > A[i+1])
			break;
		else if (A[i] < A[i+1])
			r = i;
	}
	if (l >= r) {
		printf("1 1\n");
		return 0;
	}
	bool possible = true;
	for (int i = l+1; i <= r; i++)
		if (A[i-1] < A[i])
			possible = false;
	if (l > 0 && A[r] < A[l-1])
		possible = false;
	if (r < n-1 && A[l] > A[r+1])
		possible = false;
	if (!possible) {
		printf("impossible\n");
		return 0;
	}
	printf("%d %d\n", l+1, r+1);
}
