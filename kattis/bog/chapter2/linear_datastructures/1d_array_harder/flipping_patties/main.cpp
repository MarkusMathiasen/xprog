#include <bits/stdc++.h>
using namespace std;

int acts[50000];

int main() {
	memset(acts, 0, sizeof acts);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d, t; scanf("%d%d", &d, &t);
		acts[t]++;
		acts[t-d]++;
		acts[t-d-d]++;
	}
	int res = 0;
	for (int x : acts)
		res = max(x, res);
	printf("%d\n", (res+1)/2);
}
