#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> A;

int main() {
	cin >> n;
	A.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> A[i];
	if (is_sorted(A.begin(), A.end()))
		printf("INCREASING\n");
	else if (is_sorted(A.rbegin(), A.rend()))
		printf("DECREASING\n");
	else
		printf("NEITHER\n");
}
