#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll inv = 0, n;
vector<ll> A;

vector<ll> merge(vector<ll>& a, vector<ll>& b) {
	ll ia = 0, ib = 0;
	vector<ll> res;
	while (ia < (ll)a.size() || ib < (ll)b.size()) {
		if (ia >= (ll)a.size())
			res.push_back(b[ib++]);
		else if (ib >= (ll)b.size())
			res.push_back(a[ia++]);
		else if (a[ia] <= b[ib])
			res.push_back(a[ia++]);
		else if (a[ia] > b[ib])
			res.push_back(b[ib++]), inv += a.size()-ia;
		else
			throw ia;
	}
	return res;
}

vector<ll> mergesort(vector<ll>& a) {
	ll an = a.size();
	if (an < 2)
		return a;
	vector<ll> b;
	for (ll i = an/2; i < an; i++)
		b.push_back(a[i]);
	for (ll i = an/2; i < an; i++)
		a.pop_back();
	a = mergesort(a);
	b = mergesort(b);
	return merge(a, b);
}

int main() {
	scanf("%lld", &n);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	A = mergesort(A);
	printf("%lld\n", inv);
}
