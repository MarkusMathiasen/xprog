#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_map<string, string> party;
	unordered_map<string, int> votes;
	string line; getline(cin, line);
	while (n--) {
		string cand, part;
		getline(cin, cand);
		getline(cin, part);
		party[cand] = part;
	}
	int m; cin >> m;
	getline(cin, line);
	int maxVotes = 0;
	while (m--) {
		getline(cin, line);
		votes[line]++;
		maxVotes = max(maxVotes, votes[line]);
	}
	vector<string> res;
	for (auto& [k,v] : votes)
		if (v == maxVotes)
			res.push_back(k);
	if (res.size() == 1)
		cout << party[res[0]] << "\n";
	else
		cout << "tie\n";
}
