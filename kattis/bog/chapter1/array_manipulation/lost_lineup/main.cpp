#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int n;
ii A[100];

int main() {
	scanf("%d", &n); n--;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i].first), A[i].second=i+2;
	sort(A, A+n);
	printf("1");
	for (int i = 0; i < n; i++)
		printf(" %d", A[i].second);
	printf("\n");
}
