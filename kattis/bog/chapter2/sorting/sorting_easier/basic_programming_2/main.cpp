#include <bits/stdc++.h>
using namespace std;

int N, t;
vector<int> A;

int main() {
	scanf("%d%d", &N, &t);
	A.assign(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	if (t == 1) {
		int l = 0, r = N-1;
		while (l < r && A[l] + A[r] != 7777)
			if (A[l] + A[r] > 7777)
				r--;
			else
				l++;
		printf(l < r ? "Yes\n" : "No\n");
	} else if (t == 2) {
		bool res = true;
		for (int i = 1; i < N; i++)
			res &= A[i] != A[i-1];
		printf(res ? "Unique\n" : "Contains duplicate\n");
	} else if (t == 3) {
		int res = -1;
		for (int i = 0; i + N/2 < N; i++)
			if (A[i] == A[i+N/2])
				res = A[i];
		printf("%d\n", res);
	} else if (t == 4) {
		if (N%2 == 0)
			printf("%d %d\n", A[N/2-1], A[N/2]);
		else
			printf("%d\n", A[N/2]);
	} else if (t == 5) {
		for (int x : A)
			if (100 <= x && x <= 999)
				printf("%d ", x);
		printf("\n");
	} else
		throw t;
}
