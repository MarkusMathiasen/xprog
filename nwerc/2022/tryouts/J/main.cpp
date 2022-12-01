#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int x, y; scanf("%d%d%d", &x, &x, &y);
		vector<int> res;
		if (y > x)
			res = {x, y};
		else
			res = {1, 2, 3, max(4, max(y+2, x+3)-y+2), x+2, max(y+2, x+3)};
		printf("%d", t);
		bool possible = true;
		for (int i = 1; i < (int)res.size(); i++)
			possible &= res[i] > res[i-1];
		if (possible) {
			printf(" %ld", res.size());
			for (int x : res)
				printf(" %d", x);
		}
		else
			printf(" NO PATH");
		printf("\n");
	}
}
