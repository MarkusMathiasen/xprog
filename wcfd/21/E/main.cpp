#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; scanf("%d%d", &a, &b);
	int volA = 0, volB = 0;
	while (a--) {
		int v, c; scanf("%d%d", &v, &c);
		volA += v*c;
	}
	while (b--) {
		int v, c; scanf("%d%d", &v, &c);
		volB += v*c;
	}
	printf(volA == volB ? "same\n" : "different\n");
}
