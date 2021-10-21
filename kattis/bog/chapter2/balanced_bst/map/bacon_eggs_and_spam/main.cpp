#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n && n) {
		string s; getline(cin, s);
		map<string, set<string>> m;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			stringstream ss(s);
			string name; ss >> name;
			while (ss >> s)
				m[s].insert(name);
		}
		for (auto& [k,v]: m) {
			cout << k;
			for (const string& x : v)
				cout << " " << x;
			cout << "\n";
		}
		cout << "\n";
	}
}
