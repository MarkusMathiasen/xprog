#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LSB(x) ((-x)&x)

int n, q;
vector<ll> ft;

void update(int i, int d) {
	while (i <= n)
		ft[i] += d, i += LSB(i);
}

ll sum(int i) {
	ll res = 0;
	while (i > 0)
		res += ft[i], i -= LSB(i);
	return res;
}

int main() {
	scanf("%d%d", &n, &q);
	ft.assign(n+1, 0);
	while (q--) {
		char cmd; scanf(" %c", &cmd);
		if (cmd == '+') {
			int i, d; scanf("%d%d", &i, &d); i++;
			update(i, d);
		}
		else if (cmd == '?') {
			int i; scanf("%d", &i);
			printf("%lld\n", sum(i));
		}
		else throw cmd;
	}
}
