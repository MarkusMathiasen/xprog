#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<bool> A(1001, 0);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		A[x] = true;
	}
	for (int i = 0; i < n-1; i++) {
		int x; scanf("%d", &x);
		A[x] = false;
	}
	for (int i = 0; i < 1001; i++)
		if (A[i])
			printf("%d\n", i);
}
