#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
	cin >> t;
	while (t--) {
		int res = 0, x, prev;
		cin >> prev;
		while (cin >> x) {
			if (!x) break;
			res += max(0, x-prev*2);
			prev = x;
		}
		cout << res << endl;
	}
}
