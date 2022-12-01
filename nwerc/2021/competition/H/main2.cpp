#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

vector<int> log;
vector<vector<ii>> lookup;
ll K, n;
vector<ll> cumsum;
vector<ll> arr;

void buildSparseTable() {
	ll n = arr.size();
	log.assign(n+1, 0);
	log[1] = 0;
	for (int i = 2; i <= n; i++)
		log[i] = log[i/2] + 1;
	K = log[n];
	lookup.assign(n, vector<ii>(K+1, ii(0, 0)));
	for (int i = 0; i < n; i++)
		lookup[i][0] = ii(arr[i], i);
	
	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			lookup[i][j] = max(lookup[i][j-1], lookup[i + (1 << (j - 1))][j - 1]);
}

ii query(ll L, ll R) {
	int j = log[R - L + 1];
	return max(lookup[L][j], lookup[R - (1 << j) + 1][j]);
}

ii queryPrime(ll L, ll R) {
	if (L <= R)
		return query(L, R);
	else
		return max(query(0, R), query(L, n-1));
}

void prefix() {
	cumsum.assign(n+1, 0);
	for (int i = 1; i <= n; i++)
		cumsum[i] = arr[i-1]+cumsum[i-1];
}

ll sumOfRange(ll L, ll R) {
	if (L <= R)
		return cumsum[R+1] - cumsum[L];
	else
		return cumsum[R+1] + (cumsum.back() - cumsum[L]);
}

ll mod(ll x) {
	if (x < 0)
		return x+n;
	if (x >= n)
		return x-n;
	return x;
}

bool solve(ll l, ll r, ll start) {
	if (mod(r+1) == l)
		return false;
	if (l == r)
		return arr[l] <= start;
	ii idx = queryPrime(l, r);

}

int main() {
	
}
