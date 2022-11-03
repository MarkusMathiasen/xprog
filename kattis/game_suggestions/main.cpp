#include <bits/stdc++.h>
using namespace std;

int F, S, C;
vector<int> Fn, Cn, Sn;
vector<unordered_map<int, int>> graph;
unordered_map<string, int> m;
int cnt = 0;
string line, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> F >> S >> C;
	int start = F + S + S + C;
	int finish = F + S + S + C + 1;
	Fn.assign(F, 0);
	Cn.assign(C, 0);
	Sn.assign(C, 0);
	graph.assign(finish+1, unordered_map<int, int>());
	// First layer
	for (int i = 0; i < F; i++)
		graph[start][i] = 1;
	// Second layer
	getline(cin, line);
	for (int i = 0; i < F; i++) {
		getline(cin, line);
		stringstream ss(line);
		while (ss >> s) {
			if (!m.count(s))
				m[s] = cnt++;
			graph[i][F+m[s]] = 1;
		}
	}
	// Third layer
	for (int i = 0; i < S; i++)
		graph[F+i][F+S+i] = 1;
	// Fourth layer
	for (int c = 0; c < C; c++) {
		getline(cin, line);
		stringstream ss(line);
		ss >> Cn[c];
		while (ss >> s)
			graph[F+S+m[s]][F+S+S+c] = 1;
	}
	// Fifth layer
	for (int i = 0; i < C; i++)
		graph[F+S+S+i][finish] = Cn[i];
	// Max flow
	int N = F + S + S + C + 2;
	int res = 0;
	for (; true; res++) {
		vector<int> p(N, -1);
		queue<int> q; q.push(F+S+S+C);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto [u,w] : graph[v]) {
				if (w <= 0 || p[u] != -1)
					continue;
				p[u] = v;
				q.push(u);
			}
		}
		int v = finish;
		if (p[v] == -1)
			break;
		while (v != start) {
			graph[p[v]][v] -= 1;
			graph[v][p[v]] += 1;
			v = p[v];
		}
	}
	printf("%d\n", res);
}
