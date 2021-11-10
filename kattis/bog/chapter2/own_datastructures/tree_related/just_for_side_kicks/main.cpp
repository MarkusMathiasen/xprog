#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LSB(x) ((-x)&x)

int N, Q;
vector<vector<ll>> ft;
vector<int> V(6, 0), P;

void update(int type, int i, ll am) {
	while (i <= N)
		ft[type][i] += am,
		i += LSB(i);
}

ll sum(int x) {
	ll total = 0;
	for (int i = 0; i < 6; i++) {
		ll res = 0;
		int k = x;
		while (k > 0)
			res += ft[i][k],
			k -= LSB(k);
		total += res*V[i];
	}
	return total;
}

ll sum(int left, int right) {
	return sum(right) - sum(left-1);
}

int main() {
	scanf("%d%d", &N, &Q);
	ft.assign(6, vector<ll>(N+1, 0));
	for (int i = 0; i < 6; i++)
		scanf("%d", &V[i]);
	P.assign(N+1, 0);
	for (int i = 1; i <= N; i++) {
		char c;
		scanf(" %c\n", &c);
		P[i] = c - '1';
		update(P[i], i, 1);
	}
	while (Q--) {
		int cmd, a, b; scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 1) {
			b--;
			update(b, a, 1);
			update(P[a], a, -1);
			P[a] = b;
		}
		else if (cmd == 2) {
			a--;
			V[a] = b;
		}
		else if (cmd == 3) {
			printf("%lld\n", sum(a, b));
		}
		else throw cmd;
	}
}
