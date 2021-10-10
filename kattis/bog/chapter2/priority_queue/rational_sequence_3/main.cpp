#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int t, n; scanf("%d%d", &t, &n);
		stack<bool> left;
		while (n > 1) {
			left.push(n%2 == 0);
			n /= 2;
		}
		int up = 1, down = 1;
		while (!left.empty()) {
			bool b = left.top(); left.pop();
			if (b)
				down += up;
			else
				up += down;
		}
		printf("%d %d/%d\n", t, up, down);
	}
}
