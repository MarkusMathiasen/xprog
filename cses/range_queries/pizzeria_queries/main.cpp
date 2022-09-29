#include <bits/stdc++.h>
using namespace std;

struct node {
	int left, right;
	int bl = 0;
	int br = 0;
};

int n, q;
vector<node> st;

int best(int i, int k) {
	if (st[i].right <= k)
		return k - st[i].right + st[i].br;
	else if (st[i].left >= k)
		return st[i].left - k + st[i].bl;
	else
		return min(best(i*2, k), best(i*2+1, k));
}

void update(int i, int k, int x) {
	if (st[i].left > k || st[i].right < k)
		return;
	if (st[i].left == k && st[i].right == k)
		st[i].bl = st[i].br = x;
	else {
		update(i*2, k, x);
		update(i*2+1, k, x);
		st[i].bl = min(st[i*2].bl, st[i*2].right-st[i*2].left+1 + st[i*2+1].bl);
		st[i].br = min(st[i*2+1].br, st[i*2+1].right-st[i*2+1].left+1 + st[i*2].br);
	}
}

void init_st(int i, int left, int right) {
	st[i].left = left;
	st[i].right = right;
	if (left != right) {
		init_st(i*2, left, (left+right)/2);
		init_st(i*2+1, (left+right)/2+1, right);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	st.assign(4*n, node());
	init_st(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		update(1, i, k);
	}
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int k, x; scanf("%d%d", &k, &x);
			update(1, k, x);
		} else {
			int k; scanf("%d", &k);
			printf("%d\n", best(1, k));
		}
	}
}
