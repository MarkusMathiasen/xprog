#include <bits/stdc++.h>

using namespace std;

int n, k;
int A[100001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int q = 0; q < k; q++) {
		int x; scanf("%d", &x);
		int upper = n;
		int lower = 0;
		while (lower < upper) {
			int mid = (upper + lower) / 2;
			if (A[mid] < x)
				lower = mid+1;
			else
				upper = mid;
		}
		printf(A[lower] == x ? "YES\n" : "NO\n");
	}
}
