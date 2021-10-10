#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	int R = 0, C = 0;
	for (int i = 1; i <= floor(sqrt(n)); i++)
		if (n%i == 0)
			R = i, C = n/i;
	char A[R][C];
	int x = 0;
	for (int col = 0; col < C; col++)
		for (int row = 0; row < R; row++)
			A[row][col] = s[x++];
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			printf("%c", A[row][col]);
	printf("\n");
}
