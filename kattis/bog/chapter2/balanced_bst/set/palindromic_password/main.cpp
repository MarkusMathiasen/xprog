#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	set<int> pals;
	for (int i = 0; i < 1000; i++) {
		int j = i;
		int x = 1000*j;
		x += 100*(j%10);
		j /= 10;
		x += 10*(j%10);
		j /= 10;
		x += j;
		pals.insert(x);
	}
	while (n--) {
		int x; scanf("%d", &x);
		int res = 0;
		for (int p : pals)
			if (abs(res-x) > abs(p-x))
				res = p;
		printf("%06d\n", res);
	}
}
