#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A(100000, 0);

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int q = 0; q < k; q++) {
		int x; scanf("%d", &x);
		int lower = 0;
		int upper = n;
		while (lower < upper) {
			int mid = (lower + upper) / 2;
			if (A[mid] > x)
				upper = mid;
			else
				lower = mid+1;
		}
		printf("%d\n", lower);
	}
}
