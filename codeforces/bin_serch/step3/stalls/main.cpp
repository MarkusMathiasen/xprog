#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A;

bool pos(int x) {
	int res = 1;
	int prev = A[0];
	for (int i = 1; i < n; i++)
		if (A[i] - prev >= x)
			prev = A[i], res++;
	return res >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int low = 1;
	int high = 1e9+2;
	while (low < high) {
		int mid = (low + high) / 2;
		if (pos(mid))
			low = mid+1;
		else
			high = mid;
	}
	printf("%d\n", low-1);
}
