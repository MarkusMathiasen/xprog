#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, k; scanf("%d%d", &n, &k);
		bool on = true;
		for (int i = 0; i < n; i++)
			on &= !!(k & (1 << i));
		printf("Case #%d: %s\n", t, on ? "ON" : "OFF");
	}
}
