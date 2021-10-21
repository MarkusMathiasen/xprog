#include <bits/stdc++.h>
using namespace std;
#define si pair<string, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_map<string, vector<string>> toCat;
	unordered_map<string, int> catCount;
	while (n--) {
		string cat; int w; cin >> cat >> w;
		catCount[cat] = 0;
		for (int i = 0; i < w; i++) {
			string x; cin >> x;
			toCat[x].push_back(cat);
		}
	}
	string s;
	while (cin >> s)
		for (const string& cat : toCat[s])
			catCount[cat]++;
	vector<string> res;
	int resAm = 0;
	for (auto& [k,v] : catCount)
		if (v == resAm)
			res.push_back(k);
		else if (v > resAm)
			resAm = v, res = {k};
	sort(res.begin(), res.end());
	for (const string& x : res)
		printf("%s\n", x.c_str());
}
