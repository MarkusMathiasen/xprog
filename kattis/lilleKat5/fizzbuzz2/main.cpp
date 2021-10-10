#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int res = 0;
	int resVal = -1;
	for (int j = 1; j <= n; j++) {
		int att = 0;
		for (int i = 1; i <= m; i++) {
			string s; cin >> s;
			string ans = "";
			if (i % 3 == 0)
				ans += "fizz";
			if (i % 5 == 0)
				ans += "buzz";
			if (ans == "")
				ans = to_string(i);
			if (s == ans)
				att++;
		}
		if (att > resVal) {
			resVal = att;
			res = j;
		}
	}
	cout << res << endl;
}
