#include <bits/stdc++.h>
using namespace std;


int main() {
	int N, t;
	scanf("%d%d", &N, &t);
	int A[N];
	for (int i = 0; i < N; i++)
		scanf("%d", A+i);
	if (t == 1)
		printf("7\n");
	if (t == 2) {
		if (A[0] > A[1])
			printf("Bigger\n");
		else if (A[0] == A[1])
			printf("Equal\n");
		else
			printf("Smaller\n");
	}
	if (t == 3) {
		sort(A, A+3);
		printf("%d\n", A[1]);
	}
	if (t == 4) {
		long long res = 0;
		for (int x : A)
			res += x;
		printf("%lld\n", res);
	}
	if (t == 5) {
		long long res = 0;
		for (int x : A)
			res += x % 2 == 0 ? x : 0;
		printf("%lld\n", res);
	}
	if (t == 6) {
		for (int x : A)
			printf("%c", 'a'+(x%26));
		printf("\n");
	}
	if (t == 7) {
		vector<bool> vis(N, false);
		int i = 0;
		while (i < N-1) {
			if (vis[i]) break;
			vis[i] = true;
			i = A[i];
		}
		if (i >= N)
			printf("Out\n");
		else if (i == N-1)
			printf("Done\n");
		else
			printf("Cyclic\n");
	}
}
