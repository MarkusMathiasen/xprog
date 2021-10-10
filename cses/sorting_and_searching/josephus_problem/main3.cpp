#include <bits/stdc++.h>

using namespace std;

int n, N, k;
vector<int> res, ft;

void update(int i; int k) {
	while (i > 0)
		ft[i] += k, i += i&(-i);
}

int sum(int i) {
	int res = 0;
	while (i)
		res += ft[i], i -= i&(-i);
	return res;
}

int main() {
	cin >> n >> k;
	N = n+1;
	ft.assign(n+1, 0);
	pos = 0;
	while (--N) {
		pos = (pos+k-1)%N +1;

	}
}
