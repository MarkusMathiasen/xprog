#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

ll n, sum = 0, maxi = -1, maxv = -1;
vector<ll> A;
vector<vector<ll>> sparse;

int K, N;

// Sparse table from https://cp-algorithms.com/data_structures/sparse-table.html
void sparseInit() {
	int x = 1;
	int log = 0;
	while (x < 2*n)
		x = x<<1,
		log++;
	K = log+2;
	N = 2*n;
	sparse.assign(N, vector<ll>(K+1, 0));
	for (int i = 0; i < n; i++)
		sparse[i][0] = sparse[i+n][0] = A[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j - 1))][j - 1]);
}

long long maxq(int L, int R) {
	if (R < L)
		R += n;
	long long res = 0;
	for (int j = K; j >= 0; j--) {
		if ((1 << j) <= R - L + 1) {
			res = max(res, sparse[L][j]);
			L += 1 << j;
		}
	}
	return res;
}

ll mod(ll x) {
	if (x < 0)
		x += n;
	if (x >= n)
		x -= n;
	return x;
}

bool possible(ll startv) {
	ll mySum = sum-maxv;
	ll l = mod(maxi-1);
	ll r = mod(maxi+1);
	ll prevv = maxv;
	while (l != r) {
		if (mySum+startv < prevv)
			return false;
		if (A[l] >= A[r] && mySum-A[l]+startv >= A[l]) {
			prevv = A[l];
			mySum -= A[l];
			l = mod(l-1);
		}
		else {
			prevv = A[r];
			mySum -= A[r];
			r = mod(r+1);
		}
	}
	if (mySum+startv < prevv)
		return false;
	return startv >= mySum;
}

int main() {
	scanf("%lld", &n);
	A.assign(n, 0);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	for (ll x : A)
		sum += x;
	for (ll i = 0; i < n; i++)
		if (A[i] > maxv)
			maxv = A[i], maxi = i;
	sparseInit();
	ll low = 0;
	ll high = 1e14;
	while (low < high) {
		ll mid = (low+high)/2;
		if (possible(mid))
			high = mid;
		else
			low = mid+1;
	}
	printf("%lld\n", low);
}
