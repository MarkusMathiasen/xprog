#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, s, n; scanf("%d%d%d", &t, &s, &n);
	int low_am = s;
	int prev_t = 0;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		low_am = min((x-prev_t)+low_am, s);
		low_am = s-low_am;
		prev_t = x;
	}
	low_am = min(s, low_am+(t-prev_t));
	printf("%d\n", s-low_am);
}
