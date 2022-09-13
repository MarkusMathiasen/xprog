#include <bits/stdc++.h>
using namespace std;

vector<set<int>> graph;
vector<int> A;
vector<bool> seen;
int N, E; 

int check(int idx) { // return next idx
	seen[A[idx]] = true;
	int v = A[idx++];
	while (graph[v].size()) {
		if (idx == N || idx == -1)
			return idx;
		int nxt = A[idx];
		if (!graph[v].count(nxt)) {
			bool seenAll = true;
			for (int x : graph[v])
				seenAll &= seen[x];
			return seenAll ? idx : -1;
		}
		graph[v].erase(nxt);
		graph[nxt].erase(v);
		idx = check(idx);
	}
	return idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> E;
	graph.assign(N, set<int>());
	while (E--) {
		int a, b; cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	string s; getline(cin, s); getline(cin, s);
	stringstream ss(s);
	int x;
	bool result = true;
	seen.assign(N, false);
	while (ss >> x) {
		result &= 0 <= x && x < N;
		seen[x] = true;
		A.push_back(x);
	}
	for (bool b : seen)
		result &= b;
	result &= (int)A.size() == N;
	if (!result) {
		printf("NO\n");
		return 0;
	}
	seen.assign(N, false);
	int idx = check(0);
	printf(idx == N ? "YES\n" : "NO\n");
}
