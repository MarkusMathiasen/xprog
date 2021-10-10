#include <bits/stdc++.h>
using namespace std;

int A[3];

int main() {
	scanf("%d %d %d", A, A+1, A+2);
	sort(A, A+3);
	int d1 = A[1]-A[0], d2 = A[2]-A[1];
	if (d1 < d2)
		printf("%d\n", A[1]+d1);
	else if (d1 == d2)
		printf("%d\n", A[2]+d1);
	else
		printf("%d\n", A[0]+d2);
}
