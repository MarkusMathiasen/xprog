#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int T;
int s, e;

int msb(int x) {
	for (int i = 0; i < 11; i++)
		if ((1<<i) > x)
			return i;
	return -1;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string s1, s2; cin >> s1 >> s2;
		s = stoi(s1, nullptr, 2);
		e = stoi(s2, nullptr, 2);
		queue<ii> Q;
		Q.push(ii(s, 0));
		vector<int> vis(1<<10, false);
		int res = -1;
		while (!Q.empty()) {
			int v = Q.front().first;
			int d = Q.front().second;
			Q.pop();
			if (v > (1<<9))
				continue;
			if (vis[v])
				continue;

			vis[v] = true;
			if (v == e)
				res = d;
			if (v != 0) {
				Q.emplace((v ^ ((1 << msb(v))-1), d+1);
				Q.emplace(v << 1, d+1);
			}
			else
				Q.emplace(1, d+1);

		}
		if (res == -1)
			printf("Case #%d: IMPOSSIBLE\n", t);
		else
			printf("Case #%d: %d\n", t, res);
	}
}
