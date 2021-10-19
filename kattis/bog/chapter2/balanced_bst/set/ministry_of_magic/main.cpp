#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, p; scanf("%d%d", &c, &p);
	set<int> cands;
	vector<vector<int>> priorities(p, vector<int>(c, 0));
	vector<int> members(p, -1);
	vector<int> index(p, 0);
	for (int i = 0; i < p; i++) {
		scanf("%d", &members[i]);
		for (int j = 0; j < c; j++)
			scanf("%d", &priorities[i][j]);
		cands.insert(priorities[i][0]);
	}
	while (cands.size() > 1) {
		map<int, int> votes;
		for (int i = 0; i < p; i++) {
			while (!cands.count(priorities[i][index[i]]))
				index[i]++;
			votes[priorities[i][index[i]]] += members[i];
		}
		int loser = votes.begin()->first;
		for (auto& [k,v] : votes)
			if (v < votes[loser])
				loser = k;
		cands.erase(loser);
	}
	printf("%d\n", *cands.begin());
}
