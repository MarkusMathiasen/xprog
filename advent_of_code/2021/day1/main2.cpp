#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> A;
	int x;
	while (scanf("%d", &x) != EOF)
		A.push_back(x);
	int res = 0;
	int prev = A[0] + A[1] + A[2];
	for (int i = 2; i < (int)A.size()-1; i++)
		x = A[i-1] + A[i] + A[i+1],
		res += x > prev,
		prev = x;
	printf("%d\n", res);
}		
