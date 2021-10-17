#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T, n;
ll ds = 100000; //digit size
ll a, b, c;
ll x, y;
ll A[1000000];
ll B[1000000];
ll C[1000000];
int f[100000];
int g[100000];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%lld%lld%lld", &a, &b, &c);
		scanf("%lld%lld", &x, &y);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		A[0] = a, f[a%ds]++, g[a/ds]++;
		for (int i = 1; i < n; i++)
			A[i] = (A[i-1]*b+a)%c, f[A[i]%ds]++, g[A[i]/ds]++;
		// Radix sort begins
		for (int i = 1; i < ds; i++)
			f[i] += f[i-1], g[i] += g[i-1];
		for (int i = n-1; i >= 0; i--)
			B[--f[A[i]%ds]] = A[i];
		for (int i = n-1; i >= 0; i--)
			C[--g[B[i]/ds]] = B[i];
		// Radix sort ends
		ll v = 0;
		for (int i = 0; i < n; i++)
			v = (v*x+C[i])%y;
		printf("%lld\n", v);
	}
}
