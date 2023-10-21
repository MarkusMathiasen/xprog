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

pair<vi, ll> reduce(vi A, ll target) {
	if (sz(A) == 0)
		return {{}, 0};
	if (sz(A) == 1)
		return {A, A[0]};
	ll sum = 0; for (ll x : A) sum += x;
	ll last = A.back(); A.pop_back();
	auto [v1,sum1] = reduce(A, target-last);
	v1.push_back(last);
	sum1 += last;
	rep(i, 0, sz(A)) {
		if ((i == sz(A)-1 || A[i] != A[i+1]) && sum-last-A[i] + last*A[i] <= target) {
			ll el = A[i];
			A.erase(A.begin()+i);
			A.push_back(el*last);
			auto [v2,sum2] = reduce(A, target);
			if (target-sum2+sz(v2) < target-sum1+sz(v1))
				sum1 = sum2,
				v1 = v2;
			A.pop_back();
			A.insert(A.begin()+i, el);
		}
	}
	return {v1, sum1};
}

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
			auto [v,sum1] = reduce(f, 41);
			while (sum1 < 41) {
				v.push_back(1);
				sum1++;
			}
			sort(all(v));
			printf("%lld", sz(v));
			for (ll x : v) printf(" %lld", x);
			printf("\n");
		}
	}
}
