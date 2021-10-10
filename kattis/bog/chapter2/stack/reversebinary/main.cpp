#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int msb = 31-__builtin_clz(n);
	int res = 0;
	for (int i = 0; i <= msb; i++) 
		res |= n&(1 << (msb-i)) ? (1 << i) : 0;
	printf("%d\n", res);
}
