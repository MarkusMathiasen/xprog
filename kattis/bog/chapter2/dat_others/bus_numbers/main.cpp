#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	if (n == 1) {
		printf("%d\n", A[0]);
		return 0;
	}
	if (n == 2) {
		printf("%d %d\n", A[0], A[1]);
		return 0;
	}
	printf("%d", A[0]);
	bool dash = false;
	for (int i = 1; i < n-1; i++) {
		bool cdash = A[i-1]+1 == A[i] && A[i+1]-1 == A[i];
		if (cdash) {
			dash = cdash;
			continue;
		}
		else if (!cdash) {
			if (dash)
				printf("-%d", A[i]);
			else
				printf(" %d", A[i]);
		}
		dash = cdash;
	}
	if (dash)
		printf("-%d\n", A[n-1]);
	else
		printf(" %d\n", A[n-1]);
}
