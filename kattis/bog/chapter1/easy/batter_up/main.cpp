#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int x;
	int high = 0, low = 0;
	while (scanf("%d", &x) != EOF) {
		if (x == -1)
			continue;
		high += x;
		low++;
	}
	printf("%f\n", (double)high/low);
}
