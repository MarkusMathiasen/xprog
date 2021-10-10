#include <bits/stdc++.h>

using namespace std;
#define ll long long

string r;
ll nb, ns, nc;
ll cb, cs, cc;
ll pb, ps, pc;
ll money;

bool pos(ll x) {
	ll sum = 0;
	sum += max((ll)0, (x*cb-nb)*pb);
	sum += max((ll)0, (x*cs-ns)*ps);
	sum += max((ll)0, (x*cc-nc)*pc);
	return sum <= money;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> nb >> ns >> nc >> pb >> ps >> pc >> money;
	cb = cs = cc = 0;
	for (char c : r) {
		if (c == 'B')
			cb++;
		if (c == 'S')
			cs++;
		if (c == 'C')
			cc++;
	}
	ll high = 1e14;
	ll low = 0;
	while (low < high) {
		ll mid = (low + high)/2;
		if (pos(mid))
			low = mid+1;
		else
			high = mid;
	}
	cout << low-1 << endl;
}
