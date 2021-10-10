#include <bits/stdc++.h>

using namespace std;

int grid[4][4];
int op;

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &grid[i][j]);
	scanf("%d", &op);
	if (op == 0) {	// Left
		for (int r = 0; r < 4; r++) { // for each row
			int *row = grid[r];
			for (int _ = 0; _ < 3; _++) // op everything to the left
				for (int c = 0; c < 3; c++)
					if (row[c] == 0) {
						row[c] = row[c+1];
						row[c+1] = 0;
					}
			for (int c = 0; c < 3; c++) // merge for each column
				if (row[c] == row[c+1]) {
					row[c] *= 2;
					for (int i = c+1; i < 3; i++)
						row[i] = row[i+1];
					row[3] = 0;
				}
		}
	}
	if (op == 1) {	// Up
		for (int c = 0; c < 4; c++) { // for each column
			for (int _ = 0; _ < 3; _++)
				for (int r = 0; r < 3; r++)
					if (grid[r][c] == 0) {
						grid[r][c] = grid[r+1][c];
						grid[r+1][c] = 0;
					}
			for (int r = 0; r < 3; r++) // merge for each row
				if (grid[r][c] == grid[r+1][c]) {
					grid[r][c] *= 2;
					for (int i = r+1; i < 3; i++)
						grid[i][c] = grid[i+1][c];
					grid[3][c] = 0;
				}
		}
		
		
	}
	if (op == 2) {	// Right
		for (int r = 0; r < 4; r++) { // for each row
			int *row = grid[r];
			for (int _ = 0; _ < 3; _++)	// op everything to the right
				for (int c = 3; c > 0; c--)
					if (row[c] == 0) {
						row[c] = row[c-1];
						row[c-1] = 0;
					}
			for (int c = 3; c > 0; c--) // merge for each column
				if (row[c] == row[c-1]) {
					row[c] *= 2;
					for (int i = c-1; i > 0; i--)
						row[i] = row[i-1];
					row[0] = 0;
				}
		}
	}
	if (op == 3) {	// Down
		for (int c = 0; c < 4; c++) { // for each column
			for (int _ = 0; _ < 3; _++) // op everything down
				for (int r = 3; r > 0; r--)
					if (grid[r][c] == 0) {
						grid[r][c] = grid[r-1][c];
						grid[r-1][c] = 0;
					}
			for (int r = 3; r > 0; r--) // merge for each row
				if (grid[r][c] == grid[r-1][c]) {
					grid[r][c] *= 2;
					for (int i = r-1; i > 0; i--)
						grid[i][c] = grid[i-1][c];
					grid[0][c] = 0;
				}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}
