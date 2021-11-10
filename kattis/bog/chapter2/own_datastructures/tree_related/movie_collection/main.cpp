#include <bits/stdc++.h>
using namespace std;
#define LSB(x) ((-x)&x)

vector<int> ft;
int m, r;

void update(int i, int am) {
	while (i <= m+r)
		ft[i] += am,
		i += LSB(i);
}

int sum(int i) {
	int res = 0;
	while (i > 0)
		res += ft[i],
		i -= LSB(i);
	return res;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &r);
		ft.assign(m+r+1, 0);
		for (int i = r+1; i <= m+r; i++)
			update(i, 1);
		vector<int> pos(m+1, 0);
		for (int i = 1; i <= m; i++)
			pos[i] = r+i;
		for (int i = r; i > 0; i--) {
			int x; scanf("%d", &x);
			update(pos[x], -1);
			printf("%d ", sum(pos[x]));
			pos[x] = i;
			update(i, 1);
		}
		printf("\n");
	}
}
