#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> uf, siz, ran, rea;
vector<ll> sum;

int n, m;

int find(int x) {
	if (uf[x] == -1)
		return x;
	return find(uf[x]);
}

void join(int x, int y) {
	x = find(x); y = find(y);
	if (x == y)
		return;
	if (ran[x] < ran[y])
		swap(x, y);
	if (ran[x] == ran[y])
		ran[x]++;
	uf[y] = x;
	siz[x] += siz[y];
	sum[x] += sum[y];
}

void move(int a, int b) {
	int rootA = find(rea[a]);
	int rootB = find(rea[b]);
	siz[rootA]--;
	siz[rootB]++;
	sum[rootA] -= a;
	sum[rootB] += a;
	rea[a] = rea[b];
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		uf.assign(n+1, -1);
		siz.assign(n+1, 1);
		ran.assign(n+1, 0);
		sum.assign(n+1, -1);
		rea.assign(n+1, 0);
		for (int i = 0; i <= n; i++)
			sum[i] = i, rea[i] = i;
		while (m--) {
			int cmd; scanf("%d", &cmd);
			if (cmd == 1) {
				int a, b; scanf("%d%d", &a, &b);
				join(rea[a], rea[b]);
			}
			else if (cmd == 2) {
				int a, b; scanf("%d%d", &a, &b);
				move(a, b);
			}
			else if (cmd == 3) {
				int x; scanf("%d", &x);
				x = find(rea[x]);
				printf("%d %lld\n", siz[x], sum[x]);
			}
			else throw cmd;
		}
	}
}
