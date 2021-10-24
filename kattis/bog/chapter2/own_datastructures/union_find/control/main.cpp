#include <bits/stdc++.h>
using namespace std;

int uf[500001], s[500001] = {1};

int find(int x) {
	if (x == uf[x])
		return x;
	return uf[x] = find(uf[x]);
}
void join(int x, int y) {
	uf[x] = y;
	if (x != y)
		s[y] += s[x];
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < 500001; i++)
		uf[i] = i, s[i] = 1;
	int res = 0;
	while (n--) {
		int m; scanf("%d", &m);
		unordered_map<int, int> ing;
		for (int i = 0; i < m; i++) {
			int x; scanf("%d", &x);
			x = find(x);
			ing[x]++;
		}
		bool possible = true;
		for (auto& [k,v] : ing)
			possible &= v == s[k];
		if (possible) {
			res++;
			int joiner = ing.begin()->first;
			for (auto& [k,v] : ing)
				join(k, joiner);
		}
	}
	printf("%d\n", res);
}
