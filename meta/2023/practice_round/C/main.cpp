#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
ll N;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		ll res = -1;
		cin >> N;
		A.assign(2*N-1, 0);
		rep(i, 0, 2*N-1) cin >> A[i];
		sort(all(A));
		ll sum = 0;
		for (ll x : A) sum += x;
		ll rem = 0, s = 0, other_res = -1;
		bool possible = false;
		// Edge case
		if (N == 1) {
			res = 1;
			goto end;
		}
		// Try buying cheaper apple, than everything else
		rem = sum-A.back();
		s = rem/(N-1);
		res = s-A.back();
		possible = 1 <= res && res <= A.front();
		for (int i = 0; possible && i < sz(A)/2; i++)
			possible &= A[i] + A[sz(A)-2-i] == s;
		if (possible) goto end;
		// Try buying more expensive apple, than everything else
		rem = sum-A.front();
		s = rem/(N-1);
		res = s - A.front();
		possible = res >= A.back();
		for (int i = 0; possible && i < sz(A)/2; i++)
			possible &= A[i+1] + A[sz(A)-1-i] == s;
		if (possible) {
			other_res = res;
		}
		// Try buying apple with middle price
		s = A.front() + A.back();
		rem = sum - A.front() - A.back();
		res = s*(N-1) - rem;// rem + res == s*(N-1)
		possible = A.front() <= res && res <= A.back();
		A.push_back(res);
		sort(all(A));
		for (int i = 0; possible && i < sz(A)/2; i++)
			possible &= A[i] + A[sz(A)-1-i] == s;
		if (!possible) {
			res = other_res;
		}
end:
		printf("%lld\n", res);
	}
}
