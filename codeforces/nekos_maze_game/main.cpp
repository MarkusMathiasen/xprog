#include <bits/stdc++.h>

using namespace std;

int n, q;
int grid[2][200002];
int blocks = 0;

int main(){
	scanf("%d %d", &n, &q);
	while (q--){
		int a, b; scanf("%d %d", &a, &b); a--;
		int f = grid[a][b] ? -1 : 1;
		grid[a][b] = !grid[a][b];
		blocks += f * (grid[!a][b-1] + grid[!a][b] + grid[!a][b+1]);
		printf(blocks ? "No\n" : "Yes\n");
	}
}
