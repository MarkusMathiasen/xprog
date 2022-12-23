#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	int T; cin >> T;
	rep(t, 1, T+1) {
		int N, K; cin >> N >> K;
		string s; cin >> s;
		int k = 0;
		rep(i, 0, sz(s)/2)
            k += s[i] != s[sz(s)-i-1];
        printf("Case #%d: %d\n", t, abs(k-K));
	}
}
