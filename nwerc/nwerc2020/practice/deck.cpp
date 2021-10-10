#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;

int main() {
	cin >> n;
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int res = 0;
	int l = 0;
	int r = n-1;
	for (int i = 1; i < n; i++) {
		if (res == 0) {
			if (A[i-1] < A[i]) {
				l = i;
			}
			if (A[i-1] > A[i]) {
				res = 1;
				r = i;
				if (l > 0 && A[l-1] > A[i])
					res = 3;
				continue;
			}
		}
		if (res == 1) {
			if (A[i-1] < A[i]) {
				if (A[l] <= A[i])
					res = 2;
				else
					res = 3;
			}
			if (A[i-1] >= A[i]) {
				r = i;
			}
		}
		if (res == 2) {
			if (A[i-1] > A[i])
				res = 3;
		}
	}
	if (res == 3) {
		printf("impossible\n");
		return 0;
	}
	printf("%d %d\n", l+1, r+1);
}
