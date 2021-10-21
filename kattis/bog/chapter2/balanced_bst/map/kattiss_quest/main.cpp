#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll large = 1e6;

struct quest {
	int E;
	ll G;
	quest(int E, ll G) : E(E), G(G) {}
	bool operator < (const quest& a) const {
		if (E != a.E)
			return E > a.E;
		return G > a.G;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	multiset<quest> quests;
	while (N--) {
		string cmd; cin >> cmd;
		if (cmd == "add") {
			int E; ll G; cin >> E >> G;
			quests.insert(quest(E, G));
		}
		else if (cmd == "query") {
			int X; cin >> X;
			ll res = 0;
			auto it = quests.lower_bound(quest(X, large));
			while (it != quests.end()) {
				res += it->G;
				X -= it->E;
				quests.erase(it);
				it = quests.lower_bound(quest(X, large));
			}
			printf("%lld\n", res);
		}
		else throw cmd;
	}
}
