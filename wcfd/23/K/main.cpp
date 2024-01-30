#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	ll players, cards; cin >> players >> cards;
	bool yes = cards%2 || cards/2 >= players-1;
	bool no = (players != 2 && cards > 1) || cards == 0;
	if (yes && no) printf("MAYBE\n");
	else if (yes) printf("YES\n");
	else if (no) printf("NO\n");
}