#include <bits/stdc++.h>
using namespace std;

vector<int> p, s;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	p.assign(n, 0);
	s.assign(n, 1);
	for (int i = 0; i < n; i++)
		p[i] = i;
	while (q--) {
		char cmd; scanf(" %c", &cmd);
		if (cmd == 't') {
			int a, b; scanf("%d%d", &a, &b); a--; b--;
			a = find(a);
			b = find(b);
			if (a != b) {
				p[a] = b;
				s[b] += s[a];
			}
		}
		else if (cmd == 's') {
			int a; scanf("%d", &a); a--;
			printf("%d\n", s[find(a)]);
		}
		else throw cmd;
	}
}
