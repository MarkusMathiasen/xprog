#include <bits/stdc++.h>

using namespace std;

int n, m;
int mod = 1e9+7;
int grid[1000000][1000000];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grid[i][j] = -1;
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		grid[a][b] = 0;
	}
	grid[0][0] = 1;
	for (int i = 1; i < n; i++)
		grid[0][i] = grid[0][i] == -1 ? grid[0][i-1] : 0;
	for (int i = 1; i < n; i++){
		grid[i][0] = grid[i][0] == 0 ? 0 : grid[i-1][0];
		for (int j = 1; j < n; j++){
			
		}
	}
}
