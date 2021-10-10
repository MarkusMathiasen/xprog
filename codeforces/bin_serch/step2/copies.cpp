#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, x, y;

bool pos(ll time) {
	time -= min(x, y);
	if (time < 0) return false;
	return time/x + time/y >= n-1;
}

int main() {
	scanf("%d %d %d", &n, &x, &y);
	ll lower = 1;
	ll upper = 2e9;
	while (lower < upper) {
		ll mid = (lower + upper) / 2;
		if (!pos(mid))
			lower = mid+1;
		else
			upper = mid;
	}
	printf("%d\n", lower);
}
