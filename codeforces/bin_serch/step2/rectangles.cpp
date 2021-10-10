#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll w, h, n;

int main() {
	scanf("%lld %lld %lld", &w, &h, &n);
	ll lower = 0;
	ll upper = 1e9;
	while (lower < upper) {
		ll mid = (lower + upper) / 2;
		if ((mid/h) * (mid/w) < n)
			lower = mid+1;
		else
			upper = mid;
	}
	printf("%lld\n", lower);
}
