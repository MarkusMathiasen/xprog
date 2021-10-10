#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int C, P, X, L;
queue<int> Q;
vector<vector<int>> graph;
vector<bool> un;
vector<ii> friends; // before and now


void relax(int c) {
	if (!un[c])
		return;
	if (friends[c].first >= friends[c].second*2) {
		un[c] = false;
		Q.push(c);
		for (int f : graph[c])
			friends[f].second--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> C >> P >> X >> L;
	graph.assign(C, vector<int>());
	friends.assign(C, ii(0, 0));
	while (P--) {
		int a, b; cin >> a >> b; a--; b--;
		friends[a].first++;
		friends[a].second++;
		friends[b].first++;
		friends[b].second++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	un.assign(C, true);
	friends[L-1].second = 0;
	relax(L-1);
	while (!Q.empty()) {
		int c = Q.front(); Q.pop();
		for (int v : graph[c])
			relax(v);
	}
	cout << (un[X-1] ? "stay\n" : "leave\n");
}
