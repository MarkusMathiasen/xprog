#include <bits/stdc++.h>
using namespace std;
#define si pair<string, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	unordered_map<string, unordered_set<string>> m;
	unordered_set<string> ids, twice;
	string project;
	while (getline(cin, s) && s != "") {
		if (s == "1") {
			vector<si> res;
			for (auto& [k,v] : m) {
				res.push_back(si(k, 0));
				for (const string& x : v)
					if (!twice.count(x))
						res.back().second++;
			}
			sort(res.begin(), res.end(), [](const si& a, const si& b) {
				if (a.second != b.second)
					return a.second > b.second;
				return a.first < b.first;
			});
			for (auto& x : res)
				printf("%s %d\n", x.first.c_str(), x.second);
			m.clear();
			ids.clear();
			twice.clear();
			project = s = "";
		}
		else if (s == "0")
			break;
		else {
			if (isupper(s[0])) {
				project = s;
				m[s] = unordered_set<string>();
			}
			else {
				if (!m[project].count(s) && ids.count(s))
					twice.insert(s);
				ids.insert(s);
				m[project].insert(s);
			}
		}
	}
}
