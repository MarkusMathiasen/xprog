#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> alts;

int diff(int x, int y) {
	int res = 0;
	for (int i = 0; i < (int)alts[x].size(); i++)
		res += alts[x][i] != alts[y][i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	getline(cin, line);
	cin >> n; getline(cin, line);
	alts.assign(n, vector<string>());
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		stringstream ss(line);
		string part;
		while (getline(ss, part, ','))
			alts[i].push_back(part);
	}
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[i] = max(res[i], diff(i, j));
	int best = 100;
	for (int x : res)
		best = min(x, best);
	for (int i = 0; i < n; i++)
		if (res[i] == best) {
			for (int j = 0; j < (int)alts[i].size()-1; j++)
				cout << alts[i][j] << ",";
			cout << alts[i].back() << "\n";
		}
}
