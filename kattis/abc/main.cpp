#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, z; scanf("%d%d%d", &x, &y, &z);
	char a, b, c; scanf(" %c%c%c", &a, &b, &c);
	vector<int> A = {x, y, z};
	vector<char> B = {a, b, c};
	sort(A.begin(), A.end());
	for (char k : B)
		printf("%d ", A[k-'A']);
	printf("\n");
}
