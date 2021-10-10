#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> A, leftBig, rightBig;

int main() {
	scanf("%d", &n);
	A.assign(n, 0);
	leftBig.assign(n, 0);
	rightBig.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	leftBig[0] = A[0];
	rightBig[n-1] = A[n-1];
	for (int i = 1; i < n; i++)
		leftBig[i] = max(A[i], leftBig[i-1]);
	for (int i = n-2; i >= 0; i--)
		rightBig[i] = max(A[i], rightBig[i+1]);
	int res = 0;
	for (int i = 1; i < n-1; i++)
		res = max(res, min(leftBig[i-1], rightBig[i+1]) - A[i]);
	printf("%d\n", res);
}
