#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


ll fast_solution(vector<pii>& v) {
	ll n = sz(v);
	sort(all(v), [](const pii& a, const pii& b) {
		return a.second < b.second;
	});
	ll total = 0;
	rep(i, 0, n) total += v[i].first;
	ll res = 0;
	while (sz(v) > 1) {
		res += v.back().second;
		/*
		bool choose_small = v[0].first*2 >= total;
		ll exp1 = v.back().second;
		ll am1 = v.back().first;
		ll exp2 = v[sz(v)-2].second;
		ll am2 = v[sz(v)-2].second;
		ll cheap = v[0].second;
		if (choose_small && (cheap*2+exp1 > exp1*2 && v.back().first > 1) || (
			*/
		if (v[0].first*2 >= total && v[0].second*2+v.back().second > v.back().second + v[sz(v)-2].second) {
			// pair with the cheapest
			v[0].first--;
			v.back().first--;
		} else {
			v[sz(v)-2].first--;
			v.back().first--;
		}
		total -= 2;
		if (v[sz(v)-2].first == 0) {
			pii tmp = v.back();
			v.pop_back();
			v.pop_back();
			v.push_back(tmp);
		}
		if (v.back().first == 0) v.pop_back();
	}
	if (sz(v)) res += v[0].first*v[0].second;
	return res;
}

ll fast_solution2(vector<pii>& v) {
	vi made;
	sort(all(v), [](const pii& a, const pii& b) {
		return a.second < b.second;
	});
	ll res = 0;
	ll t = -1;
	ll i = -1;
	vector<pii> neww;
	rep(k, 0, sz(v)) {
		if (t != v[k].second) {
			if (t != -1) {
				ll total = 0;
				ll maxu = 0;
				rep(s, i, k) {
					total += v[s].first;
					maxu = max(maxu, v[s].first);
				}
				ll z;
				if (maxu <= total / 2) {
					z = total / 2;
				}
				else {
					z = total - maxu;
				}
				res += z * v[i].second;
				total -= 2 * z;
				if (total > 0) neww.push_back({total, v[i].second});
				rep(y, 0, z) made.push_back(v[i].second);
			}
			t = v[k].second;
			i = k;
		}
	}
			if (t != -1) {
				ll total = 0;
				ll maxu = 0;
				rep(s, i, sz(v)) {
					total += v[s].first;
					maxu = max(maxu, v[s].first);
				}
				ll z;
				if (maxu <= total / 2) {
					z = total / 2;
				}
				else {
					z = total - maxu;
				}
				res += z * v[i].second;
				total -= 2 * z;
				if (total > 0) neww.push_back({total, v[i].second});
				rep(y, 0, z) made.push_back(v[i].second);
			}
	v = neww;
	while (sz(v) > 1) {
		res += v.back().second;
		if (sz(v) > 2) made.push_back(v[sz(v)-2].second);
		v.back().first -= 1;
		v[sz(v)-2].first -= 1;
		if (v[sz(v)-2].first == 0) {
			pii tmp = v.back();
			v.pop_back();
			v.pop_back();
			v.push_back(tmp);
		}
		if (v.back().first == 0) v.pop_back();
	}
	sort(all(made));
	while (sz(v) > 0 && v[0].first > 0 && sz(made) > 0) {
		if (v[0].first == 1) {
			res += v[0].second;
			v[0].first--;
			break;
		}
		ll b = made.back();
		if (v[0].second*2 > b) {
			made.pop_back();
			res += b;
		}
		else {
			res += v[0].second*2;
		}
		v[0].first -= 2;
	}
	return res + (sz(v) > 0 ? v[0].first * v[0].second : 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	cin >> n;
	vector<pii> v(n, {0, 0});
	rep(i, 0, n) cin >> v[i].first >> v[i].second;
	vector<pii> v2(all(v));
	printf("%lld\n", fast_solution2(v));
}
