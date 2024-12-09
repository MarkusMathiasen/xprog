#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

unordered_set<char> lefts = {
    'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'
};

ll t, s;
string line;
vector<vi> dp;

ll calc(ll pos, bool l) {
    if (pos == sz(line)) return 0;
    if (dp[pos][l] != -1) return dp[pos][l];
    if (line[pos] == ' ' || l == (lefts.count(line[pos])>0))
        return dp[pos][l] = t+calc(pos+1, l);
    else
        return dp[pos][l] = min(1000+calc(pos+1, l), s+calc(pos, 1-l));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    cin >> t >> s;
    getline(cin, line); getline(cin, line);
    dp.assign(sz(line), vi(2, -1));
    printf("%lld\n", min(calc(0, 0), calc(0, 1)));
}
