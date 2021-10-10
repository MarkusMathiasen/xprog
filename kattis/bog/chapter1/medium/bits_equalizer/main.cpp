#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int j = 1; j <= n; j++) {
		cin >> s >> t;
		int s1 = 0, s0 = 0, sq = 0;
		for (char c : s)
			switch (c) {
				case '0': s0++; break;
				case '1': s1++; break;
				case '?': sq++; break;
			}
		int t1 = 0, t0 = 0;
		for (char c : t)
			switch (c) {
				case '0': t0++; break;
				case '1': t1++; break;
			}
		int oneSwitch = 0, zeroSwitch = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '?' || s[i] == t[i])
				continue;
			if (s[i] == '1')
				oneSwitch++;
			else
				zeroSwitch++;
		}
		zeroSwitch -= max(0, s0 - t0);
		int res = max(oneSwitch, zeroSwitch) + sq + max(0, s0 - t0);
		if (s0 + sq < t0)
			res = -1;
		printf("Case %d: %d\n", j, res);
	}
}
