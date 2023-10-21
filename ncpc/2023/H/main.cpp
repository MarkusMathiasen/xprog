#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

map<string, ll> power = {
	{"Shadow", 6},
	{"Gale", 5},
	{"Ranger", 4},
	{"Anvil", 7},
	{"Vexia", 3},
	{"Guardian", 8},
	{"Thunderheart", 6},
	{"Frostwhisper", 2},
	{"Voidclaw", 3},
	{"Ironwood", 3},
	{"Zenith", 4},
	{"Seraphina", 1}
};

ll ability(string& name, ll loc, ll friendly) {
	if (name == "Thunderheart")
		return friendly == 4 ? 6 : 0;
	if (name == "Zenith")
		return loc == 1 ? 5 : 0;
	if (name == "Seraphina")
		return friendly-1;
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vi p1_power = {0, 0, 0}, p2_power = {0, 0, 0};
	ll p1_wins = 0, p2_wins = 0;
	ll p1_sum = 0, p2_sum = 0;
	rep(i, 0, 3) {
		ll n; cin >> n;
		string name;
		rep(j, 0, n) {
			cin >> name;
			p1_power[i] += power[name] + ability(name, i, n);
		}
		cin >> n;
		rep(j, 0, n) {
			cin >> name;
			p2_power[i] += power[name] + ability(name, i, n);
		}
		p1_wins += p1_power[i] > p2_power[i];
		p2_wins += p2_power[i] > p1_power[i];
		p1_sum += p1_power[i];
		p2_sum += p2_power[i];
	}
	if (p1_wins > p2_wins || (p1_wins == p2_wins && p1_sum > p2_sum)) {
		printf("Player 1\n");
		return 0;
	}
	if (p2_wins > p1_wins || (p2_wins == p1_wins && p2_sum > p1_sum)) {
		printf("Player 2\n");
		return 0;
	}
	printf("Tie\n");
}
