#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N; cin >> N;
	double w = (double)N+1, h = sqrt(3)+2;
	printf("%.10lf %.10lf\n", w, h);
	rep(i, 0, N/2+N%2) printf("%lld %d\n", 1+2*i, 1);
	ll s = N/2+N%2;
	rep(i, N/2+N%2, N) printf("%lld %.10lf\n", 2+(i-s)*2, 1+sqrt(3));
}
