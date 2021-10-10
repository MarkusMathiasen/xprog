#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int n;

bool comp(ii a, ii b) {
	if (a.first == 12 && b.first != 12)
		return true;
	if (a.first != 12 && b.first == 12)
		return false;
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n, n) {
		vector<ii> am, pm;
		for (int i = 0; i < n; i++) {
			string t, z; cin >> t >> z;
			ii p(0, 0); sscanf(t.c_str(), "%d:%d", &p.first, &p.second);
			if (z == "a.m.")
				am.push_back(p);
			else
				pm.push_back(p);
		}
		sort(am.begin(), am.end(), comp);
		sort(pm.begin(), pm.end(), comp);
		for (ii t : am)
			printf("%d:%02d a.m.\n", t.first, t.second);
		for (ii t : pm)
			printf("%d:%02d p.m.\n", t.first, t.second);
		printf("\n");
	}
}
