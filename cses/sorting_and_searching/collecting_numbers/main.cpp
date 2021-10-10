#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> pos, A, dp;

int main() {
	cin >> n >> m;
	A.assign(n, 0);
	pos.assign(n+2, 0);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &A[i]);
		pos[A[i]] = i;
	}
	pos[pos.size()-1] = 1000000;
	dp.assign(n+1, 0);
	dp[0] = 1;
	int res = 1;
	for (int k : A) {
		dp[k] = 1;
		if (dp[k-1] == 0)
			res++;
	}

	while (m--) {
		int pa, pb; scanf(" %d %d", &pa, &pb); pa--; pb--;
		int a = min(pa, pb);
		int b = max (pa, pb);
		int va = A[a];
		int vb = A[b];
		if (pos[va-1] > a && pos[va-1] < b)
			res--;
		if (pos[va+1] > a && pos[va+1] < b)
			res++;
		if (pos[vb-1] < b && pos[vb-1] > a)
			res++;
		if (pos[vb+1] < b && pos[vb+1] > a)
			res--;
		if (va == vb-1)
			res++;
		if (va-1 == vb)
			res--;
		pos[va] = b;
		pos[vb] = a;
		A[a] = vb;
		A[b] = va;
		printf("%d\n", res);
	}
}
