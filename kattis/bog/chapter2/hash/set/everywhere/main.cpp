#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_set<string> cities;
		while (n--) {
			string s; cin >> s;
			cities.insert(s);
		}
		printf("%d\n", (int)cities.size());
	}
}
