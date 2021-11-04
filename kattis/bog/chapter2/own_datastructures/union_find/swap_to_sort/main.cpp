#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	p.assign(n, 0);
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		p[find(a)] = find(b);
	}
	bool res = true;
	for (int i = 0; i < n/2; i++)
		res &= find(i) == find(n-i-1);
	printf(res ? "Yes\n" : "No\n");
}
