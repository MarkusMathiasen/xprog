#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector<vector<string>> pref(n, vector<string>());
	vector<int> prefIdx(n, 0);
	for (int i = 0; i < n; i++) {
		int size; cin >> size; pref[i].assign(size, "");
		for (int j = 0; j < size; j++)
			cin >> pref[i][j];
	}
	int p; cin >> p;
	vector<string> rank(p, "");
	for (int i = 0; i < p; i++)
		cin >> rank[i];
	int rankIdx = 0;
	vector<vector<string>> res(n, vector<string>());
	unordered_set<string> picked;
	for (int round = 0; round < k; round++) {
		for (int owner = 0; owner < n; owner++) {
			string pick;
			while (prefIdx[owner] < (int)pref[owner].size()
				&& picked.count(pref[owner][prefIdx[owner]]))
				prefIdx[owner]++;
			while (picked.count(rank[rankIdx]))
				rankIdx++;
			if (prefIdx[owner] < (int)pref[owner].size())
				pick = pref[owner][prefIdx[owner]++];
			else
				pick = rank[rankIdx++];
			picked.insert(pick);
			res[owner].push_back(pick);
		}
	}
	for (const auto& v : res) {
		for (const auto& w : v)
			cout << w << " ";
		cout << "\n";
	}
}
