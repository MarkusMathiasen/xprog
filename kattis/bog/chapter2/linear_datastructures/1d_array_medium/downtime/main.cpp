#include <bits/stdc++.h>
using namespace std;

int A[200001];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	while (n--) {
		int x; scanf("%d", &x);
		A[x]++;
		A[x+1000]--;
	}
	int res = 0, val = 0;
	for (int i = 0; i <= 200000; i++)
		val += A[i], res = max(res, val);
	printf("%d\n", (res-1)/k + 1);
}
