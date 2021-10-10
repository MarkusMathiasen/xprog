#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;
vector<int> A;

bool pos(ll x) {
	int res = 0;
	ll sum = x;
	for (int a : A) {
		if (a > x)
			return false;
		if (a + sum > x)
			res++, sum = 0;
		sum += a;
	}
	return res <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	ll low = 1;
	ll high = 1e14;
	while (low < high) {
		ll mid = (low + high) / 2;
		if (!pos(mid))
			low = mid+1;
		else
			high = mid;
	}
	printf("%lld\n", low);
}
