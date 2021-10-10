#include <bits/stdc++.h>
using namespace std;

int a, b;
int main() {
	scanf("%d%d", &a, &b);
	int r1 = a <= b ? b - a : b - a + 360;
	int r2 = r1 - 360;
	if (r1 < -r2)
		printf("%d\n", r1);
	else if (-r2 < r1)
		printf("%d\n", r2);
	else
		printf("%d\n", r1);
}
