#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	printf("%d:\n", n);
	for (int i = 2; i < n; i++) {
		if (n % (2*i-1) == 0 || (n-i) % (2*i-1) == 0)
			printf("%d,%d\n", i, i-1);
		if (n % i == 0)
			printf("%d,%d\n", i, i);
	}
}
