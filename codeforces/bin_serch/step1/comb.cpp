#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A;

int main() {
	scanf("%d", &n);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	scanf("%d", &k);
	while (k--) {
		int l, r; scanf("%d %d", &l, &r);
		int low1 = 0;
		int up1 = n;
		while (low1 < up1) {
			int mid = (low1 + up1) / 2;
			if (A[mid] < l)
				low1 = mid+1;
			else
				up1 = mid;
		}
		int low2 = 0;
		int up2 = n;
		while (low2 < up2) {
			int mid = (low2 + up2) / 2;
			if (A[mid] < r+1)
				low2 = mid+1;
			else
				up2 = mid;
		}
		printf("%d ", low2-low1);
	}
	printf("\n");
}
