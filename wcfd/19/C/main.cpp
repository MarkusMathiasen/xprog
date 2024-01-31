#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
vector<string> nums;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
    rep(i, 0, n) {
        bool valid = true;
        string x, y; cin >> x;
        y = x; reverse(all(y));
        for (char& c : y) {
            if (c == '0' || c == '1' || c == '8') continue;
            else if (c == '9') c = '6';
            else if (c == '6') c = '9';
            else valid = false;
        }
        nums.push_back(valid && y < x ? y : x);
    }
    sort(all(nums), [](const string& x, const string& y) {
        return x + y < y + x;
    });
    for (string s : nums) printf("%s", s.c_str());
    printf("\n");
}