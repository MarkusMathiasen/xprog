#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll graph[4000][4000] = {0};
ll V, E, Q; 
bool compliment = false, transpose = false;
const ll mod = 1e9+7;

void addEdge(ll a, ll b) {
	if (transpose)
		swap(a, b);
	graph[a][b] = !compliment;
}

void removeEdge(ll a, ll b) {
	if (transpose)
		swap(a, b);
	graph[a][b] = compliment;
}

bool hasEdge(ll a, ll b) {
	if (transpose)
		swap(a, b);
	return graph[a][b] != compliment;
}

int main() {
	scanf("%lld%lld%lld", &V, &E, &Q);
	while (E--) {
		ll a, b; scanf("%lld%lld", &a, &b);
		addEdge(a, b);
	}
	while (Q--) {
		ll cmd; scanf("%lld", &cmd);
		if (cmd == 1) {
			V++;
			for (ll i = 0; i < V; i++)
				graph[i][V-1] = graph[V-1][i] = compliment;
		}
		else if (cmd == 2) {
			ll a, b; scanf("%lld%lld", &a, &b);
			addEdge(a, b);
		}
		else if (cmd == 3) {
			ll a; scanf("%lld", &a);
			for (ll i = 0; i < V; i++) {
				removeEdge(a, i);
				removeEdge(i, a);
			}
		}
		else if (cmd == 4) {
			ll a, b; scanf("%lld%lld", &a, &b);
			removeEdge(a, b);
		}
		else if (cmd == 5)
			transpose = !transpose;
		else if (cmd == 6) {
			compliment = !compliment;
			for (ll i = 0; i < 4000; i++)
				graph[i][i] = compliment;
		}
		else throw cmd;
	}
	printf("%lld\n", V);
	for (ll i = 0; i < V; i++) {
		ll factor = 1;
		ll cnt = 0;
		ll h = 0;
		for (ll j = 0; j < V; j++) {
			if (hasEdge(i, j)) {
				cnt++;
				h += factor*j;
				h %= mod;
				factor *= 7;
				factor %= mod;
			}
		}
		printf("%lld %lld\n", cnt, h);
	}
}
