#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<vector<vector<ii>>> graphs;

int main() {
	int k, n, m; scanf("%d%d%d", &k, &n, &m);
	graphs.assign(n, vector<vector<ii>>(k, vector<ii>())); // first day, then airport, then outgoing flights
	for (int i = 0; i < m; i++) {
		int u, v, d, c; scanf("%d%d%d%d", &u, &v, &d, &c); d--; u--; v--;
		graphs[d][u].push_back(ii(v, c));
	}
	vector<vector<int>> arrivals(n, vector<int>(k, 0)); // first day, then airport
	for (int i = 0; i < k*n; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
		arrivals[b][a] = c;
	}
	vector<int> people(k, 0);
	bool optimal = true;
	for (int d = 0; d < n; d++) {
		for (int a = 0; a < k; a++)
			people[a] += arrivals[d][a];
		vector<int> newPeople = people;
		for (int a = 0; a < k; a++) {
			vector<ii>& f = graphs[d][a];
			for (auto& [destination,capacity] : f) {
				newPeople[destination] += capacity;
				newPeople[a] -= capacity;
				people[a] -= capacity;
			}
			if (people[a] < 0)
				optimal = false;
		}
		people = newPeople;
	}
	printf(optimal ? "optimal\n" : "suboptimal\n");
}
