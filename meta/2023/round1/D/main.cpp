#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi v;

const ll inf = 1e9;
const ll mod = 1e9+7;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mflip = 0, mini=inf, maxi=-inf, minv = inf, maxv=-inf;
	Node(ll lo, ll hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 <= hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid+1, hi);
			maxv = max(l->maxv, r->maxv);
			maxi = l->maxv >= r->maxv ? l->maxi : r->maxi;
			minv = min(l->minv, r->minv);
			mini = l->minv <= r->minv ? l->mini : r->mini;
		}
		else maxi = mini = lo, maxv = minv = v[lo];
	}
	void flip(ll L, ll R) {
		if (R < lo || hi < L) return;
		if (L <= lo && hi <= R) {
			swap(minv,maxv);
			minv = mod-minv, maxv=mod-maxv;
			swap(mini, maxi);
			mflip ^= 1;
		}
		else {
			push(), l->flip(L, R), r->flip(L, R);
			maxv = max(l->maxv, r->maxv);
			maxi = l->maxv >= r->maxv ? l->maxi : r->maxi;
			minv = min(l->minv, r->minv);
			mini = l->minv <= r->minv ? l->mini : r->mini;
		}
	}
	void push() {
		if (mflip)
			l->flip(lo,hi), r->flip(lo,hi), mflip=0;
	}
};

ll T;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		ll N; cin >> N;
		v.assign(N, 0);
		rep(i, 0, N) cin >> v[i];
		Node* tree = new Node(v, 0, N-1);
		ll res = 0;
		ll Q; cin >> Q;
		while (Q--) {
			ll a, b; cin >> a >> b; a--; b--;
			tree->flip(a, b);
			res += tree->maxi+1;
		}
		printf("%lld\n", res);
	}
}
