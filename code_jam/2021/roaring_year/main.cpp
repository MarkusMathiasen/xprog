#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll T;
set<ll> roars;

int main() {
	for (int i = 1; i < 10000; i++) {
		string s = to_string(i);
		for (int j = i+1; true; j++) {
			s += to_string(j);
			if (s.size() >= 9)
				break;
			roars.insert(stoi(s));
		}
	}
	ios_base::sync_with_stdio(false);
	cin .tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int y; cin >> y;
		printf("Case #%d: %d\n", t, *roars.upper_bound(y));
	}
}
