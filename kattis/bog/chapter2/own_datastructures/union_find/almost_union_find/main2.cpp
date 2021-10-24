#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> uf, siz, ran;
vector<ll> sum;
vector<set<int>> kids;

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
	kids[x].insert(y);
}

void move(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA == rootB)
		return;
	// Fix if a has kids
	if (kids[a].size()) {
		auto it = kids[a].begin();
		int first = *it;
		it++;
		for (; it != kids[a].end(); it++) {
			kids[first].insert(*it);
			uf[*it] = first;
		}
		uf[first] = uf[a];
		if (uf[a] != -1)
			kids[uf[a]].insert(first);
		else {
			rootA = first;
			siz[first] = siz[a];
			sum[first] = sum[a];
			ran[first] = ran[a];
		}
	}
	kids[a].clear();
	
	// Take a out of its set
	if (uf[a] != -1)
		kids[uf[a]].erase(a);
	uf[a] = -1;
	siz[rootA]--; siz[a] = 1;
	ran[a] = 0;
	sum[rootA] -= a; sum[a] = a;

	// put a into the b-set
	join(rootB, a);
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		uf.assign(n+1, -1);
		siz.assign(n+1, 1);
		ran.assign(n+1, 0);
		kids.assign(n+1, set<int>());
		sum.assign(n+1, -1);
		for (int i = 0; i <= n; i++)
			sum[i] = i;
		while (m--) {
			int cmd; scanf("%d", &cmd);
			if (cmd == 1) {
				int a, b; scanf("%d%d", &a, &b);
				join(a, b);
			}
			else if (cmd == 2) {
				int a, b; scanf("%d%d", &a, &b);
				move(a, b);
			}
			else if (cmd == 3) {
				int x; scanf("%d", &x);
				x = find(x);
				printf("%d %lld\n", siz[x], sum[x]);
			}
			else throw cmd;
		}
	}
}
