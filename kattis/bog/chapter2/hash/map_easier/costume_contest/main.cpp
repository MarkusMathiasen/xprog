#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int lowest = n;
	map<string, int> cat;
	while (n--) {
		string s; cin >> s;
		cat[s]++;
	}
	for (auto& [k,v] : cat)
		lowest = min(lowest, v);
	for (auto& [k,v] : cat)
		if (v == lowest)
			cout << k << "\n";
}
