#include <bits/stdc++.h>
using namespace std;
#define ll long long

int A[1000000];

int main() {
	for (int t = 0; t < 30; t++) {
		int n = 1000000;
		ll a = 12432, b = 2144352, c = 1000000000;
		ll x = 123456, y = 1000000000;
		A[0] = a;
		for (int i = 1; i < n; i++)
			A[i] = (A[i-1]*b+a)%c;
		ll v = 0;
		for (int i = 0; i < n; i++)
			v = (v*x+A[i])%y;
		printf("%lld\n", v);
	}
	printf("Done\n");
}
