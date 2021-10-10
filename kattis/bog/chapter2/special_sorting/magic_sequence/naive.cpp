#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T, n;
ll ds = 1000000; //diget size
ll a, b, c;
ll x, y;
ll A[1000000];
ll B[1000000];
ll C[1000000];
int f[1000000];

ll conv(ll x, bool d) {
	if (d)
		x /= ds;
	return x%ds;
}

void countSort(ll A[], ll B[], bool d) {
	for (int i = 0; i < ds; i++)
		f[i] = 0;
	for (int i = 0; i < n; i++)
		f[A[i]%ds]++;
	for (int i = 1; i < ds; i++)
		f[i] += f[i-1];
	for (int i = n-1; i >= 0; i--)
		B[--f[A[i]%ds]] = A[i];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%lld%lld%lld", &a, &b, &c);
		scanf("%lld%lld", &x, &y);
		A[0] = a;
		for (int i = 1; i < n; i++)
			A[i] = (A[i-1]*b+a)%c;
		// Radix sort begins
		countSort(A, B, 0);
		//countSort(B, C, 1);
		//countSort(B, C, 1);
		//countSort(B, C, 1);
		/*
		countSort(2);
		countSort(3);
		countSort(4);
		*/
		// Radix sort ends
		ll v = 0;
		for (int i = 0; i < n; i++)
			v = (v*x+B[i])%y;
		printf("%lld\n", v);
	}
}
