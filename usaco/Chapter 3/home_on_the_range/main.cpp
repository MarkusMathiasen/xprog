/*
ID: markus3
LANG: C++
TASK: range
*/
#include <bits/stdc++.h>

int N;
int grid[250][250];
int results[251];

int main () {
	FILE *fin  = fopen ("range.in", "r");
	FILE *fout = fopen ("range.out", "w");
	fscanf(fin, "%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			char c; fscanf(fin, " %c", &c);
			grid[i][j] = c == '0' ? 0 : 1;
		}
	for (int i = 1; i < 250; i++){
		for (int x = 0; x < N-i; x++)
			for (int y = 0; y < N-i; y++){
				grid[x][y] = grid[x][y] && grid[x+1][y] && grid[x][y+1] && grid[x+1][y+1];
				results[i] += grid[x][y];
			}
	}
	for (int i = 1; i < N; i++){
		if (!results[i]) break;
		fprintf(fout, "%d %d\n", i+1, results[i]);
	}
}
