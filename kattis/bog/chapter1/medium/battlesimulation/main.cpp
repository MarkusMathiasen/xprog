#include <bits/stdc++.h>
using namespace std;

string s, res = "";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (i < (int)s.size()-2) {
			set<char> set({s[i], s[i+1], s[i+2]});
			if (set.size() == 3) {
				res += "C";
				i += 2;
				continue;
			}
		}
		if (c == 'R')
			res += 'S';
		if (c == 'B')
			res += 'K';
		if (c == 'L')
			res += 'H';
	}
	cout << res << endl;
}
