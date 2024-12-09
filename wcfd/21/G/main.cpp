#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi dice(7, 0);
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

vector<string> grid(5, "");

void read_dice(ll x, ll y) {
	ll d = 0;
	queue<pii> q;
	q.emplace(x, y);
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		if (grid[x][y] == '-' || grid[x][y] == '|') continue;
		if (grid[x][y] == '.') continue;
		d += grid[x][y] == 'o';
		grid[x][y] = '.';
		rep(k, 0, 4) q.emplace(x+dx[k], y+dy[k]);
	}
	dice[d]++;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	rep(i, 0, 5) getline(cin, grid[i]);
	rep(i, 0, 5) read_dice(1, 1ll+10ll*i);
	rep(i, 1, 7) printf("%lld ", dice[i]*i);
	printf("\n");
	ll p1 = 0, p2 = 0;
	rep(i, 1, 7)
		if (dice[i] > 1) p2 = p1, p1 = 2*i;
	printf("%lld ", p1); // one pair
	printf("%lld ", p2 > 0 ? p1 + p2 : 0); // two pairs
	ll t = 0;
	rep(i, 1, 7) if (dice[i] > 2) t = 3*i;
	printf("%lld ", t); // three of a kind
	ll f = 0;
	rep(i, 1, 7) if (dice[i] > 3) f = 4*i;
	printf("%lld ", f); // four of a kind
	printf("%lld ", (p1*3/2 > t && t > 0) ? t+p1 : (t > 0 && p2 > 0 ? t+p2 : 0)); // full house
	printf("%d ", (dice[1] && dice[2] && dice[3] && dice[4] && dice[5])*15); // small straight
	printf("%d ", (dice[2] && dice[3] && dice[4] && dice[5] && dice[6])*20); // big straight
	printf("%d ", dice[1] == 5 || dice[2] == 5 || dice[3] == 5 || dice[4] == 5 || dice[5] == 5 ? 50 : 0); // yatzy
	printf("%lld ", dice[1] + dice[2]*2 + dice[3]*3 + dice[4]*4 + dice[5]*5 + dice[6]*6); // chance
	printf("\n");
}
