#include <bits/stdc++.h>
using namespace std;

int a, b, h, res = 0;

int main() {
	scanf("%d%d%d", &a, &b, &h);
	int curr = 0;
	while (curr + b < h)
		res++, curr += a-b;
	printf("%d\n", max(1, res));
}
