#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t;

int main() {
	cin >> t;
	while (t--) {
		ll p, r, f; cin >> p >> r >> f;
		ll res = 0, cur = p;
		while (cur <= f)
			res++, cur *= r;
		cout << res << endl;
	}
}
