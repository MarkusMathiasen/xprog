#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	if (n == 5 || n == 7 || n == 11) {
		printf("impossible\n");
		return 0;
	}
	if (n % 2 == 0) {
		printf("2x%d\n", n/2);
		return 0;
	}
	else {
		for (int i = 3; i < 400; i += 2) {
			for (int j = 3; j < 400; j += 2) {
				if (i*j == n) {
					printf("%dx%d\n", i, j);
					return 0;
				}
			}
		}
		n -= 9;
		printf("3x3 2x%d\n", n/2);
	}
}
