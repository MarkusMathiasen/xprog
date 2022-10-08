#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll r; scanf("%lld", &r);
	ll x = r+1, y = 0;
	ll bestx = x, besty = y;
	ll best_dist = (r+1)*(r+1);
	while (y <= r) {
		while (y*y + (x-1)*(x-1) > r*r)
			x--;
		if (y*y + x*x < best_dist)
			best_dist = y*y + x*x,
			bestx = x,
			besty = y;
		y++;
	}
	printf("%lld %lld\n", bestx, besty);
}
