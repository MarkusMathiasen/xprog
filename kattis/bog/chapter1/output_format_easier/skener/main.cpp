#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, C, zr, zc; scanf("%d%d%d%d", &R, &C, &zr, &zc);
	for (int r = 0; r < R; r++) {
		vector<char> row(C, ' ');
		for (int c = 0; c < C; c++)
			scanf(" %c", &row[c]);
		for (int a = 0; a < zr; a++) {
			for (char c : row)
				for (int b = 0; b < zc; b++)
					printf("%c", c);
			printf("\n");
		}
	}
}
