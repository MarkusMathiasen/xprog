#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> s;
		int n = ceil(sqrt(s.size()));
		char A[n][n];
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				int x = row*n+col;
				if (x < (int)s.size())
					A[row][col] = s[x];
				else
					A[row][col] = '*';
			}
		}
		for (int col = 0; col < n; col++)
			for (int row = n-1; row >= 0; row--)
				if (A[row][col] != '*')
					printf("%c", A[row][col]);
		printf("\n");
	}
}
