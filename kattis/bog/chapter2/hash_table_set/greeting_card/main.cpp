#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>

int main() {
	ll n; scanf("%lld", &n);
	set<ii> points;
	for (ll i = 0; i < n; i++) {
		ll a, b; scanf("%lld%lld", &a, &b);
		points.insert(ii(a, b));
	}
	ll res = 0;
	for (auto& [a,b] : points) {
		res += points.count(ii(a+1680, b+1118));
		res += points.count(ii(a+1680, b-1118));
		res += points.count(ii(a-1680, b+1118));
		res += points.count(ii(a-1680, b-1118));
		res += points.count(ii(a+1118, b+1680));
		res += points.count(ii(a+1118, b-1680));
		res += points.count(ii(a-1118, b+1680));
		res += points.count(ii(a-1118, b-1680));
		res += points.count(ii(a+2018, b));
		res += points.count(ii(a-2018, b));
		res += points.count(ii(a, b+2018));
		res += points.count(ii(a, b-2018));
	}
	printf("%lld\n", res/2);
}
