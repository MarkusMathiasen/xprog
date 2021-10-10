#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int b, k; scanf("%d%d", &b, &k);
		int res = 0;
		for (int i = 1; i <= ceil(sqrt(b-1)); i++) {
			if ((b-1)%i == 0) {
				if (i <= k)
					res = max(res, i);
				if ((b-1)/i <= k)
					res = max(res, (b-1)/i);
			}
		}
		printf("%d\n", res);
	}
}
