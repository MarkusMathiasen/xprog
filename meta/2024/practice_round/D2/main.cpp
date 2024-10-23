#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
ll N, G;
ll A[300000];

void merge_sort(ll *A, ll A_size) {
	if (A_size == 1) return;
	ll A1_size = A_size/2, A2_size = A1_size + (A_size&1ll);
	ll *A1 = A, *A2 = A+A1_size;
	merge_sort(A1, A1_size);
	merge_sort(A2, A2_size);
	// Merge
	vi B(A_size); ll a1 = 0, a2 = 0;
	rep(b, 0, A_size) {
		if (a1 == A1_size) B[b] = A2[a2++] - (A1_size - a1);
		else if (a2 == A2_size) B[b] = A1[a1++] + a2;
		else B[b] = A1[a1] < A2[a2] ? A1[a1++] + a2 : A2[a2++] - (A1_size - a1);
	}
	rep(b, 0, A_size) A[b] = B[b];
}

bool is_sorted(ll *A, ll A_size) {
	rep(i, 0, A_size-1) if (A[i] >= A[i+1]) return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		cin >> N >> G;
		rep(i, 0, N) cin >> A[N-1-i];
		while (!is_sorted(A, N)) {
			merge_sort(A, N);
		}
		ll best = 0;
		rep(i, 0, N) if (abs(A[i]-G) <= abs(A[best]-G)) best = i;
		printf("%lld %lld\n", N-best, abs(A[best]-G));
	}
}