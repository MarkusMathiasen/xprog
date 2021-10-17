#include <bits/stdc++.h>
using namespace std;

int n, inv = 0;
vector<int> A;

void swap(int a, int b) {
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
	inv++;
}

int main() {
	scanf("%d", &n);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			if (A[j-1] > A[j])
				swap(j-1, j);
	printf("%d\n", inv);
}
