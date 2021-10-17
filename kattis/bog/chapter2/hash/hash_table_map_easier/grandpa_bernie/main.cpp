#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_map<string, vector<int>> trips;
	while (n--) {
		string s; int y; cin >> s >> y;
		trips[s].push_back(y);
	}
	int q; cin >> q;
	for (auto& [k,v] : trips)
		sort(v.begin(), v.end());
	while (q--) {
		string s; int x; cin >> s >> x;
		printf("%d\n", trips[s][x-1]);
	}
}
