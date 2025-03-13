#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int n, q;
vi A, am, p;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n >> q;
	A.resize(n);
	p.resize(n);
	am.assign(n, 0);
	rep(i, 0, n) cin >> A[i];
	stack<int> s;
	for (int i = n-1; i >= 0; i--) {
		while (!s.empty() && A[i] >= A[s.top()]) s.pop();
		p[i] = s.empty() ? n : s.top();
		s.push(i);
	}
	UF uf(n+1);
	while (q--) {
		char c; cin >> c;
		if (c == '+') {
			int i, a; cin >> i >> a; i--;
			i = uf.find(i);
			while (i < n && a > 0) {
				int used = min(A[i]-am[i], a);
				am[i] += used; a -= used;
				if (A[i] == am[i]) uf.join(p[i], i), i = uf.find(i);
			}
		} else if (c == '?') {
			int i; cin >> i; i--;
			printf("%d\n", am[i]);
		} else assert(false);
	}
}
