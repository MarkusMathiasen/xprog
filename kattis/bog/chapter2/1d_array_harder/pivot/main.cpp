#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int A[n], partMin[n], partMax[n];
	for (int i = 0; i < n; i++)
		scanf("%d", A+i);
	partMax[0] = A[0];
	for (int i = 1; i < n; i++)
		partMax[i] = max(partMax[i-1], A[i]);
	partMin[n-1] = A[n-1];
	for (int i = n-2; i >= 0; i--)
		partMin[i] = min(partMin[i+1], A[i]);
	int res = 0;
	for (int i = 0; i < n; i++)
		res += partMax[i] <= A[i] && A[i] <= partMin[i];
	printf("%d\n", res);
}
