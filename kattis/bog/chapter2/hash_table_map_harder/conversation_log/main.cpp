#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m; cin >> m;
	unordered_map<string, unordered_set<string>> wordsUsed;
	unordered_map<string, int> wordCount;
	string minName;
	while (m--) {
		string name; cin >> name;
		minName = name;
		string line; getline(cin, line);
		stringstream ss(line);
		string w;
		while (ss >> w) {
			wordCount[w]++;
			wordsUsed[name].insert(w);
		}
	}
	for (auto& [k,v] : wordsUsed)
		if (k.size() < minName.size())
			minName = k;
	vector<is> res;
	for (string w : wordsUsed[minName]) {
		bool all = true;
		for (auto& [k,v] : wordsUsed)
			all &= v.count(w);
		if (all)
			res.push_back(is(-wordCount[w], w));
	}
	sort(res.begin(), res.end());
	for (auto& [k,v] : res)
		printf("%s\n", v.c_str());
	if (!res.size())
		printf("ALL CLEAR\n");
}
