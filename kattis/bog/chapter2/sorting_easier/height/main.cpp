#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int t; scanf("%d", &t);
		vector<int> A(20, 0);
		int res = 0;
		for (int i = 0; i < 20; i++) {
			scanf("%d", &A[i]);
			for (int x : A)
				res += x > A[i];
		}
		printf("%d %d\n", t, res);
	}
}
