#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		for (int j = 0; j < n; j++)
			printf(j < i ? "9" : "0");
		while (x--)
			printf("9");
		printf(" ");
	}
	printf("\n");
}
