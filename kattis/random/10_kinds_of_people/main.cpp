#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int r, c, q;
vector<vector<char>> ma;
vector<vector<int>> comps;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &r, &c);
	ma.assign(r, vector<char>(c, '?'));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf(" %c", &ma[i][j]);

	comps.assign(r, vector<int>(c, 0));
	int count = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			queue<ii> Q;
			Q.emplace(i, j);
			while (!Q.empty()) {
				int x = Q.front().first;
				int y = Q.front().second;
				Q.pop();
				if (x < 0 || x >= r || y < 0 || y >= c)
					continue;
				if (comps[x][y] || ma[i][j] != ma[x][y])
					continue;
				comps[x][y] = count;
				Q.emplace(x-1, y);
				Q.emplace(x+1, y);
				Q.emplace(x, y-1);
				Q.emplace(x, y+1);
			}
			count++;
		}
	}
	
	scanf("%d", &q);
	while (q--) {
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &b, &x, &y);
		a--; b--; x--; y--;
		if (comps[a][b] == comps[x][y])
			printf(ma[a][b] == '0' ? "binary\n" : "decimal\n");
		else
			printf("neither\n");
	}
}
