#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll inv = 0;
vector<ll> A;

vector<ll> merge(vector<ll>& a, vector<ll>& b) {
	vector<ll> res;
	ll ai = 0, bi = 0;
	while (ai < (ll)a.size() || bi < (ll)b.size()) {
		if (ai >= (ll)a.size())
			res.push_back(b[bi++]);
		else if (bi >= (ll)b.size()) 
			res.push_back(a[ai++]);
		else if (a[ai] <= b[bi])
			res.push_back(a[ai++]);
		else if (b[bi] < a[ai])
			res.push_back(b[bi++]), inv += a.size()-ai;
		else
			throw ai;
	}
	return res;
}

vector<ll> mergesort(vector<ll>& a) {
	ll n = a.size();
	if (n < 2)
		return a;
	vector<ll> b;
	for (ll i = n/2; i < n; i++)
		b.push_back(a[i]);
	for (ll i = n/2; i < n; i++)
		a.pop_back();
	a = mergesort(a);
	b = mergesort(b);
	return merge(a, b);
}

int main() {
	scanf("%lld", &n);
	A.assign(n, 0);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	A = mergesort(A);
	printf("%lld\n", inv);
}
