#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(ll lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (ll i = 4; i < lim; i += 2) isprime[i] = 0;
	for (ll i = 3; i*i < lim; i += 2) if (isprime[i])
		for (ll j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

ll T;
vi primes = eratosthenesSieve(100'000);

vi factor(ll x) {
	vi res;
	for (ll p : primes) {
		if (p*p > x) break;
		while (x % p == 0) {
			res.push_back(p);
			x /= p;
		}
	}
	if (x > 1) res.push_back(x);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		ll P; cin >> P;
		vi f = factor(P);
		ll sum = 0;
		for (ll x : f) sum += x;
		if (sum > 41)
			printf("-1\n");
		else {
			while (sum < 41) {
				f.push_back(1);
				sum++;
			}
			printf("%lld", sz(f));
			sort(all(f));
			for (ll x : f) printf(" %lld", x);
			printf("\n");
		}
	}
}
