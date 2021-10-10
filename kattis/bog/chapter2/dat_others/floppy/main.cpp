#include <bits/stdc++.h>
using namespace std;

int main() {
	int f; scanf("%d", &f);
	bool possible = true;
	while (f--) {
		int t, n; scanf("%d%d", &t, &n); t++;
		vector<bool> A(t, true);
		while (n--) {
			int a, b; scanf("%d%d", &a, &b);
			int d = b-a;
			vector<bool> nA = A;
			for (int i = 0; i < t; i++) {
				nA[i] = i-d >= 0 && A[i-d];
				nA[i] = nA[i] || (i+d < t && A[i+d]);
			}
			A = nA;
		}
		bool found = false;
		for (bool b : A)
			found |= b;
		possible &= found;
	}
	printf(possible ? "possible\n" : "impossible\n");
}
