#include <bits/stdc++.h>
using namespace std;
#define si pair<string, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		unordered_map<string, int> m;
		int n; cin >> n;
		while (n--) {
			string toy; int am; cin >> toy >> am;
			m[toy] += am;
		}
		vector<si> res;
		for (auto& [k,v] : m)
			res.push_back(si(k, v));
		sort(res.begin(), res.end(), [](const si& a, const si& b) {
			if (a.second != b.second)
				return a.second > b.second;
			return a.first < b.first;
		});
		printf("%d\n", (int)res.size());
		for (auto& [a,b] : res)
			printf("%s %d\n", a.c_str(), b);
	}
}
