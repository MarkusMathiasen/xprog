#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> uf, siz, sum, ran;
vector<vector<ll>> kids;
ll n, m;

ll find(ll x) {
	if (uf[x] == -1)
		return x;
	return find(uf[x]);
}

void join(ll x, ll y) {
	x = find(x); y = find(y);
	if (x == y)
		return;
	if (ran[x] < ran[y])
		swap(x, y);
	if (ran[x] == ran[y])
		ran[x]++;
	uf[y] = x;
	kids[x].push_back(y);
	siz[x] += siz[y];
	sum[x] += sum[y];
}

void move(ll a, ll b) { // moves a to the set containing b
	ll rootA = find(a);
	ll rootB = find(b);
	if (rootA == rootB)
		return;
	if (a == rootA) {
		if (kids[a].size()) {
			ll first = kids[a][0];
			siz[first] = siz[a]-1; siz[a] = 1;
			sum[first] = sum[a]-a; sum[a] = a;
			ran[first] = kids[a].size() > 1 ? ran[a] : ran[a]-1; ran[a] = 0;
			uf[first] = -1; uf[a] = -1;
			for (int i = 1; i < (int)kids[a].size(); i++) {
				uf[kids[a][i]] = first;
				kids[first].push_back(kids[a][i]);
			}
			kids[a] = vector<ll>();
		}
	}
	else {
		if (kids[a].size()) {
			ll first = kids[a][0];
			siz[rootA]--; siz[a] = 1;
			sum[rootA] -= a; sum[a] = a;
			ran[a] = 0;
			for (int i = 1; i < (int)kids[a].size(); i++) {
				uf[kids[a][i]] = first;
				kids[first].push_back(kids[a][i]);
			}
			kids[a] = vector<ll>();
			auto it = find(kids[uf[a]].begin(), kids[uf[a]].end(), a);
			kids[uf[a]].erase(it);
			kids[uf[a]].push_back(first);
			uf[first] = uf[a]; uf[a] = -1;
		}
	}
	join(rootB, a);
}

int main() {
	while (scanf("%lld%lld", &n, &m) != EOF) {
		uf.assign(n+1, -1);
		sum.assign(n+1, 0);
		siz.assign(n+1, 1);
		ran.assign(n+1, 0);
		kids.assign(n+1, vector<ll>());
		for (ll i = 1; i <= n; i++)
			sum[i] = i;
		while (m--) {
			ll cmd; scanf("%lld", &cmd);
			if (cmd == 1) {
				ll a, b; scanf("%lld%lld", &a, &b);
				join(a, b);
			}
			else if (cmd == 2) {
				ll a, b; scanf("%lld%lld", &a, &b);
				move(a, b);
			}
			else if (cmd == 3) {
				ll x; scanf("%lld", &x);
				x = find(x);
				printf("%lld %lld\n", siz[x], sum[x]);
			}
			else throw cmd;
		}
	}
}
