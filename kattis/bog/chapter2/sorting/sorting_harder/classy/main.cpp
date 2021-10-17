#include <bits/stdc++.h>
using namespace std;
#define ps pair<vector<int>, string>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<ps> res(n, ps());
		string klass;
		for (int i = 0; i < n; i++) {
			string klass, s;
			cin >> res[i].second >> klass >> s;
			res[i].second.pop_back();
			vector<int>& v = res[i].first;
			stringstream ss(klass);
			while (getline(ss, s, '-')) {
				if (s == "upper")
					v.push_back(1);
				else if (s == "middle")
					v.push_back(0);
				else if (s == "lower")
					v.push_back(-1);
				else
					throw s;
			}
			for (int i = v.size(); i < 10; i++)
				v.insert(v.begin(), 0);
		}
		sort(res.begin(), res.end(), [](ps const& a, ps const& b) {
			vector<int> const& va = a.first, vb = b.first;
			for (int i = 9; i >= 0; i--)
				if (va[i] != vb[i])
					return va[i] > vb[i];
			return a.second < b.second;
		});
		for (ps p : res)
			printf("%s\n", p.second.c_str());
		for (int i = 0; i < 30; i++)
			printf("=");
		printf("\n");
	}
}
