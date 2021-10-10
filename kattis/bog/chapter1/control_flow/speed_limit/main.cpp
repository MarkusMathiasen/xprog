#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	while (cin >> n) {
		if (n == -1)
			break;
		int s, t, res = 0, prev = 0;
		while (n--) {
			cin >> s >> t;
			res += (t-prev)*s;
			prev = t;
		}
		printf("%d miles\n", res);
	}
}
