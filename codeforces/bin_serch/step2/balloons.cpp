#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll m, n;
vector<vector<ll>> A(1000, vector<ll>(3, 0));

bool pers(ll p, ll bal, ll time) {
	ll t = A[p][0];
	ll z = A[p][1];
	ll y = A[p][2];
	ll pauses = (bal-1) / z;
	return t*bal + y*pauses <= time;
}

ll persVal(ll p, ll time) {
	ll low = 0;
	ll high = 15001;
	while (low < high) {
		ll mid = (low + high) / 2;
		if (pers(p, mid, time))
			low = mid+1;
		else
			high = mid;
	}
	return low-1;
}

bool pos(ll time) {
	ll res = 0;
	for (ll i = 0; i < n; i++)
		res += persVal(i, time);
	return res >= m;
}

int main() {
	scanf("%lld %lld", &m, &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld %lld", &A[i][0], &A[i][1], &A[i][2]);
	ll low = 0;
	ll high = 2e9;
	while (low < high) {
		ll mid = (low + high) / 2;
		if (pos((ll)mid))
			high = mid;
		else
			low = mid+1;
	}
	printf("%lld\n", low);
	for (int i = 0; i < n; i++) {
		ll v = persVal(i, low);
		printf("%lld ", min(v, m));
		m -= min(v, m);
	}
	printf("\n");
}
