#include <bits/stdc++.h>
using namespace std;
#define lsb(x) ((-x)&x)

int N;
vector<int> ft, pos;

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

int main() {
	scanf("%d", &N);
	ft.assign(N+1, 0);
	for (int i = 1; i <= N; i++)
		update(i, 1);
	pos.assign(N+1, 0);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		pos[x] = i;
	}
	for (int i = 0; i < N; i++) {
		if (i%2 == 0) {
			int x = pos[i/2+1];
			update(x, -1);
			printf("%d\n", sum(x-1));
		}
		else {
			int x = pos[N-i/2];
			update(x, -1);
			printf("%d\n", N-i-1-sum(x-1));
		}
	}
}
