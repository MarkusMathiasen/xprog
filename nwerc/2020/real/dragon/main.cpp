#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, ll>

ll n, d;
set<ll> squares;
int guess = 0;

ll mysqrt(ll x) {
	ll lower = 0;
	ll upper = 1e9;
	while (lower < upper) {
		ll mid = (lower+upper)/2;
		if (mid*mid < x)
			lower = mid+1;
		else
			upper = mid;
	}
	return lower;
}

int main() {
	for (ll i = 0; i <= (ll)1e6; i++)
		squares.insert(i*i);
	cin >> n;
	while (n) {
		guess++;
		assert(guess < 1000);
		cout << "0 0" << endl;
		cin >> d;
		if (d == 0) {
			n--;
			continue;
		}
		set<ii> att;
		for (ll s : squares)
			if (squares.count(d-s))
				att.insert(ii(mysqrt(s), mysqrt(d-s)));
		for (ii at : att) {
			cout << at.first << " " << at.second << endl;
			guess++;
			assert(guess < 1000);
			ll ans; cin >> ans;
			if (ans == 0) {
				n--;
				break;
			}
		}
	}
}
