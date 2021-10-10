#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define iii pair<ii, int>

int l, k, s;
vector<int> laps;
vector<pair<ii, int>> tim;
map<int, int> toIndex;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> k >> s;
	int count = 1;
	laps.assign(l+1, 0);
	tim.assign(l+1, iii(ii(0, 0), 0));
	for (int i = 0; i < l; i++) {
		int num; string s; cin >> num >> s;
		if (toIndex[num] == 0)
			toIndex[num] = count++;
		int idx = toIndex[num];
		tim[idx].first.first += stoi(s.substr(0, 2));
		tim[idx].first.second += stoi(s.substr(3, 2));
		tim[idx].second = num;
		laps[idx]++;
	}
	for (int i = 1; i <= l; i++) {
		tim[i].first.first += tim[i].first.second/60;
		tim[i].first.second %= 60;
	}
	sort(tim.begin(), tim.end());
	for (iii t : tim) {
		if (laps[toIndex[t.second]] >= k)
			printf("%d\n", t.second);
	}
}
