#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	if (n == k)
		printf("impossible\n");
	else
		for (int i = 1; i <= k; i++)
			printf("open %d using %d\n", i, n);
}
