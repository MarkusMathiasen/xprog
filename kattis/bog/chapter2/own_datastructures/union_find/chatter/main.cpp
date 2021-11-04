#include <bits/stdc++.h>
using namespace std;

int n, r, a, b, c;
vector<int> p, siz;

int next_int() {
	return r = (r*a+b)%c;
}

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

int main() {
	while (scanf("%d%d%d%d%d", &n, &r, &a, &b, &c) != EOF) {
		p.assign(n, 0);
		siz.assign(n, 1);
		for (int i = 0; i < n; i++)
			p[i] = i;
		for (int d = 0; d < n; d++) {
			int x, y;
			do {
				x = next_int() % n;
				y = next_int() % n;
			} while (x == y);
			x = find(x);
			y = find(y);
			if (x != y) {
				p[y] = x;
				siz[x] += siz[y];
			}
		}
		map<int, int> m;
		int total = 0;
		for (int i = 0; i < n; i++)
			if (p[i] == i)
				m[siz[i]]++, total++;
		printf("%d", total);
		for (auto it = m.rbegin(); it != m.rend(); it++) {
			if (it->second == 1)
				printf(" %d", it->first);
			else
				printf(" %dx%d", it->first, it->second);
		}
		printf("\n");
	}
}
