#include <bits/stdc++.h>
using namespace std;

bool grid[101][101][101];

int main() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				grid[i][j][k] = 0;
	string on(3, ' '); int sx, ex, sy, ey, sz, ez;
	while (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d", &on[0], &sx, &ex, &sy, &ey, &sz, &ez) != EOF) {
		sx = max(sx, -50);
		ex = min(ex, 50);
		sy = max(sy, -50);
		ey = min(ey, 50);
		sz = max(sz, -50);
		ez = min(ez, 50);
		for (int x = sx; x <= ex; x++)
			for (int y = sy; y <= ey; y++)
				for (int z = sz; z <= ez; z++)
					grid[x+50][y+50][z+50] = on[1] == 'n';
	}
	int res = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				res += grid[i][j][k];
	printf("%d\n", res);
}
