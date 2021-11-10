#include <bits/stdc++.h>
using namespace std;
#define lsb(i) ((-i)&i)

int N, K;
vector<int> ft;

void update(int i, int am) {
	while (i <= N)
		ft[i] += am,
		i += lsb(i);
}

int sum(int i) {
	int res = 0;
	while (i > 0)
		res += ft[i],
		i -= lsb(i);
	return res;
}
int sum(int l, int r) {
	return sum(r) - sum(l-1);
}

int main() {
	scanf("%d%d", &N, &K);
	ft.assign(N+1, 0);
	while (K--) {
		char cmd; scanf(" %c", &cmd);
		if (cmd == 'F') {
			int i; scanf("%d", &i);
			if (sum(i, i))
				update(i, -1);
			else
				update(i, 1);
		}
		else if (cmd == 'C') {
			int l, r; scanf("%d%d", &l, &r);
			printf("%d\n", sum(l, r));
		}
		else throw cmd;
	}
}
