#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n;
vector<ii> lifts;

int main() {
	cin >> n;
	lifts.assign(100001, ii(0, 0)); // first is how many mono and second is how many bi.
	for (int i = 0; i < n; i++) {
		int x, y, a; scanf("%d %d %d", &x, &y, &a);
		if (a == 1)
			lifts[y].first++;
		else
			lifts[y].second++;
	}
	int res = 0;
	int prev = lifts[0].first + lifts[0].second;
	for (int i = 1; i < 100001; i++) {
		if (lifts[i].second >= prev) {
			res += prev;
			prev = lifts[i].second+lifts[i].first;
			continue;
		}
		prev -= lifts[i].second;
		res += lifts[i].second;
		if (lifts[i].first >= prev) {
			res += prev;
			lifts[i].first -= prev;
			prev = lifts[i].first+lifts[i].second;
			continue;
		}
		res += lifts[i].first;
		lifts[i].first = 0;
		prev = lifts[i].second;
	}
	cout << res << endl;
}
