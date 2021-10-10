#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int N;
vector<vector<int>> args;
bool party

bool violate(int mp) {
	int cnt = 0;
	for (int arg : args[mp])
		cnt += party[arg] == party[mp];
	return cnt >= 3;
}

int main() {
	scanf("%d", &N);
	args.assign(N, vector<int>());
	party.assign(N, 0);
	for (int day = 0; day < 5; day++) {
		int n; scanf("%d", &n);
		while (n--) {
			int a, b; scanf("%d%d", &a, &b); a--; b--;
			args[a].push_back(b);
			args[b].push_back(a);
		}
	}
	queue<int> q;
	for (int i = 0; i < N; i++)
		q.push(i);
	while (!q.empty()) {
		int mp = q.front(); q.pop();
		if (violate(mp)) {
			party[mp] = !party[mp];
			for (int arg : args[mp])
				q.push(arg);
		}
	}
	for (bool b : party)
		printf(b ? "A" : "B");
	printf("\n");
}
