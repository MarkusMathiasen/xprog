#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<char, ll> snafutoi = {
        {'2', 2},
        {'1', 1},
        {'0', 0},
        {'-', -1},
        {'=', -2}
};

map<ll, char> mod_to_char = {
        {0, '0'},
        {1, '1'},
        {2, '2'},
        {4, '-'},
        {3, '='}
};

ll to_dec(string& s) {
    ll res = 0;
    ll pow = 1;
    for (int i = sz(s)-1; i >= 0; i--) {
        res += snafutoi[s[i]] * pow;
        pow *= 5;
    }
    return res;
}

string to_snafu(ll x) {
    string res = "";
    while (x != 0) {
        char c = mod_to_char[x % 5];
        res.push_back(c);
        x -= snafutoi[c];
        x /= 5;
    }
    reverse(all(res));
    return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    ll res = 0;
    string s; while (cin >> s) {
        res += to_dec(s);
    }
    printf("%lld\n", res);
    printf("%s\n", to_snafu(res).c_str());
}
