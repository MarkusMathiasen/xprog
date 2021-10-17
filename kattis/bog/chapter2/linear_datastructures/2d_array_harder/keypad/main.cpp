#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		char res[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = 'I';
		char A[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf(" %c", &A[i][j]);
				if (A[i][j] == '0')
					res[i][j] = 'N';
			}
		bool possible = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (A[i][j] == '0') {
					bool x = false;
					for (int k = 0; k < n; k++)
						x |= A[k][j] == '1';
					bool y = false;
					for (int k = 0; k < m; k++)
						y |= A[i][k] == '1';
					possible &= !(x && y);
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (res[i][j] == 'I') {
					int cnt = 0;
					for (int k = 0; k < n; k++)
						cnt += A[k][j] == '1';
					if (cnt == 1)
						res[i][j] = 'P';
					cnt = 0;
					for (int k = 0; k < m; k++)
						cnt += A[i][k] == '1';
					if (cnt == 1)
						res[i][j] = 'P';
				}
				
		if (!possible)
			printf("impossible\n");
		else {
			for (auto& row : res) {
				for (auto& c : row)
					printf("%c", c);
				printf("\n");
			}
		}
		printf("----------\n");
	}
}
