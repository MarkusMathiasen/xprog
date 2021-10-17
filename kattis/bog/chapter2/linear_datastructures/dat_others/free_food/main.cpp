#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<bool> A(365, 0);
	while (n--) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		for (int i = a; i <= b; i++)
			A[i] = true;
	}
	int res = 0;
	for (bool b : A)
		res += b;
	printf("%d\n", res);
}
