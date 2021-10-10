#include <bits/stdc++.h>

using namespace std;

int n, q;
int ft[1001][1001], grid[1001][1001];

void print(int p[][1001]){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}
}

void update(int x, int y, int k){
	while (x <= n){
		int Y = y;
		while (Y <= n)
			ft[x][Y] += k, Y += Y&(-Y);
		x += x&(-x);
	}
}
int sum(int x, int y){
	int res = 0;
	while (x > 0){
		int Y = y;
		while (Y > 0)
			res += ft[x][Y], Y -= Y&(-Y);
		x -= x&(-x);
	}
	return res;
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			char c; scanf(" %c", &c);
			if (c == '*') {
				grid[i][j] = 1;
				update(i, j, 1);
			}
		}
	while (q--){
		int o, a, b; scanf("%d %d %d", &o, &a, &b);
		if (o == 1){
			if (grid[a][b])
				update(a, b, -1);
			else
				update(a, b, 1);
			grid[a][b] = !grid[a][b];
			continue;
		}
		int x, y; scanf("%d %d", &x, &y);
		int res = sum(x, y) + sum(a-1, b-1);
		res -= sum(x, b-1) + sum(a-1, y);
		printf("%d\n", res);
	}
}
