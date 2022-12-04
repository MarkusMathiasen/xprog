#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll squares(double r) {
	ll res = 0;
	ll x = ceil(r), y = 0;
	while (true) {
		y++;
		while (x > 0 && x*x + y*y > r*r)
			x--;
		if (x <= 0)
			break;
		res += x;
	}
	return res*4;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll s; scanf("%lld", &s);
	double low = 0, high = 1e5, eps = 1e-8;
	while (low+eps < high && low*(1+eps) < high) {
		double mid = (low + high)/2;
		if (squares(mid) <= s)
			low = mid;
		else
			high = mid;
	}
	printf("%lf\n", low);
}
