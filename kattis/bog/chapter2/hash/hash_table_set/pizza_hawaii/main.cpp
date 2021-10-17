#include <bits/stdc++.h>
using namespace std;
#define ss pair<string, string>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<string, set<string>> eng, ita;
		while (n--) {
			string pizza; cin >> pizza;
			int x; cin >> x;
			while (x--) {
				string top; cin >> top;
				eng[top].insert(pizza);
			}
			cin >> x;
			while (x--) {
				string top; cin >> top;
				ita[top].insert(pizza);
			}
		}
		vector<ss> res;
		for (auto& [ek,ev] : eng)
			for (auto& [ik,iv] : ita)
				if (ev == iv)
					res.push_back(ss(ek, ik));
		for (auto& [s1,s2] : res)
			printf("(%s, %s)\n", s1.c_str(), s2.c_str());
		printf("\n");
	}
}
