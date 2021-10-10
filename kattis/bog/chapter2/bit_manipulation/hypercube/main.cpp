#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

ll pow(ll a, ll b) {
	ll res = 1;
	while (b--)
		res *= a;
	return res;
}

ll pos(string s) {
	ll x = 1;
	ll res = 0;
	for (ll i = 0; i < n; i++)
		x *= 2;
	bool add = 1;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (add)
				res += x-1;
			else
				res -= x-1;
			add = !add;
		}
		x /= 2;
	}
	return res;
}

int main() {
	cin >> n;
	string s1, s2; cin >> s1 >> s2;
	cout << pos(s2)-pos(s1)-1 << endl;
}
