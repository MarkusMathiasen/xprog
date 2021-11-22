#include <bits/stdc++.h>
using namespace std;

struct que {
	int l, r, c;
	int d;
	que(int l, int r, int c, int d) : l(l), r(r), c(c), d(d) {}
};

int L, R, C;

int main() {
	while (scanf("%d%d%d", &L, &R, &C), L && R && C) {
		char A[L][R][C];
		int sl, sr, sc;
		for (int l = 0; l < L; l++)
			for (int r = 0; r < R; r++)
				for (int c = 0; c < C; c++) {
					scanf(" %c", &A[l][r][c]);
					if (A[l][r][c] == 'S')
						sl = l,
						sr = r,
						sc = c;
				}
		queue<que> q;
		q.push(que(sl, sr, sc, 0));
		vector<vector<vector<int>>> dist(L, vector<vector<int>>(R, vector<int>(C, -1)));
		int res = -1;
		while (!q.empty()) {
			que x = q.front(); q.pop();
			if (x.l < 0 || x.l >= L || x.r < 0 || x.r >= R || x.c < 0 || x.c >= C)
				continue;
			if (dist[x.l][x.r][x.c] != -1)
				continue;
			if (A[x.l][x.r][x.c] == '#')
				continue;
			if (A[x.l][x.r][x.c] == 'E') {
				res = x.d;
				break;
			}
			dist[x.l][x.r][x.c] = x.d;
			q.push(que(x.l+1, x.r, x.c, x.d+1));
			q.push(que(x.l-1, x.r, x.c, x.d+1));
			q.push(que(x.l, x.r+1, x.c, x.d+1));
			q.push(que(x.l, x.r-1, x.c, x.d+1));
			q.push(que(x.l, x.r, x.c+1, x.d+1));
			q.push(que(x.l, x.r, x.c-1, x.d+1));
		}
		if (res == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", res);
	}
}
