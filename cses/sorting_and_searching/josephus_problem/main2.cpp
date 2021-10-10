#include <bits/stdc++.h>

using namespace std;

int N, n, k;
vector<int> dead, ft, lef, righ, ans;

int sum(int i) {
	int res = 0;
	while (i > 0)
		res += ft[i], i -= i&(-i);
	return res;
}
void update(int i, int k) {
	dead[i] += k;
	while (i <= n)
		ft[i] += k, i += i&(-i);
}

int inc(int i) {
	return ((i+k-1)%N)+1;
}

int main() {
	cin >> n >> k;
	k++;
	N = n+1;
	dead.assign(n+1, 0);
	lef.assign(n+1, 0);
	righ.assign(n+1, 0);
	ft.assign(n+1, 0);
	for (int i = 1; i < n; i++) {
		lef[i] = i-1;
		righ[i] = i+1;
	}
	
	int pos = 0;
	while (--N) {
		pos = inc(pos);
		int p = (sum(pos)+pos);
		ans.push_back(p);
		update(p, 1);
		if (dead[lef[p]]) {
			update(lef[p], 1);
			update(p, -1);
			righ[lef[p]] = righ[p];
			p = lef[p];
		}
		if (dead[righ[p]]) {
			update(p, dead[righ[p]]);
			update(righ[p], -dead[righ[p]]);
			righ[p] = righ[righ[p]];
		}
		pos--;
	}
	for (int i : ans)
		printf("%d ", i);
	printf("\n");
}
