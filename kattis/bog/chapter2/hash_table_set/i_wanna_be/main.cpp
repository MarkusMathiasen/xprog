#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct poke {
	ll a;
	ll d;
	ll h;
	bool operator < (const poke& p) const {return a < p.a;}
};

int main() {
	ll n, k; scanf("%lld%lld", &n, &k);
	vector<poke> A(n, poke());
	for (ll i = 0; i < n; i++)
		scanf("%lld%lld%lld", &A[i].a, &A[i].d, &A[i].h);
	set<poke> team;
	sort(A.begin(), A.end(), [](const poke& a, const poke& b) {return a.a > b.a;});
	for (ll i = 0; i < k; i++)
		team.insert(A[i]);
	sort(A.begin(), A.end(), [](const poke& a, const poke& b) {return a.d > b.d;});
	for (ll i = 0; i < k; i++)
		team.insert(A[i]);
	sort(A.begin(), A.end(), [](const poke& a, const poke& b) {return a.h > b.h;});
	for (ll i = 0; i < k; i++)
		team.insert(A[i]);
	printf("%lld\n", (ll)team.size());
}
