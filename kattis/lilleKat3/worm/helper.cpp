#include <bits/stdc++.h>
using namespace std;

int N, M, K, Q;
vector<vector<vector<int>>> dp;
int query(int x, int y, int z) {
	if (x == 0 || x == N+1)
		return 0;
	if (dp[x][y][z] != -1)
		return dp[x][y][z];
	assert(Q > 0);
	Q--;
	printf("? %d %d %d\n", x, y, z);
	fflush(stdout);
	int ans = -1;
	(void)scanf("%d", &ans);
	if (ans == -1) exit(0);
	return dp[x][y][z] = ans;
}

__attribute__((noreturn))
void guess(int x, int y, int z) {
	printf("! %d %d %d\n", x, y, z);
	exit(0);
}

int ran(int max) {
	return (rand()%max)+1;
}
void ispeak(int n) {
	if (query(n-1, 1, 1) <= query(n, 1, 1) && query(n, 1, 1) >= query(n+1, 1, 1))
		guess(n, 1, 1);
}
double magic = 0.381966;
int main() {
	(void)scanf("%d %d %d %d", &N, &M, &K, &Q);
	dp.assign(N+1, vector<vector<int>>(M+1, vector<int>(K+1, -1)));

	if (Q == 35) {
		int lval = floor(magic*N);
		int rval;
		int low = 1;
		int high = N;
		bool findRight = true;
		while (low < high) {
            if (findRight)
                rval = lval + floor((1-2*magic)*(high-low+1));
            else
                lval = rval - floor((1-2*magic)*(high-low+1));
            if (lval == rval)
                break;
            if (query(lval, 1, 1) >= query(rval, 1, 1))
                high = rval, rval = lval, findRight = false;
            else
                low = lval, lval = rval, findRight = true;
        }
        for (int i = low; i <= high; i++)
            ispeak(i);
        guess(1, 1, 1);
	}

	if (Q == 3500) {
		int big = 0;
		int bx = 0;
		int by = 0;
		int lx = 1;
		int hx = N;
		int ly = 1;
		int hy = M;
		while (lx != hx || ly != hy) {
			int p = 0;
			int v = 0;
			if (hx - lx >= hy - ly) {
				int mid = (lx + hx) / 2;
				for (int i = ly; i <= hy; i++)
					if (query(mid, i, 1) > v)
						v = query(mid, i, 1), p = i;
				if (v > big) {
					big = v;
					bx = mid;
					by = p;
					if (query(mid+1, p, 1) > v)
						lx = mid+1;
					else
						hx = mid;
				}
				else {
					if (mid >= bx)
						hx = mid;
					else
						lx = mid+1;
				}
			}
			else {
				int mid = (ly + hy) / 2;
				for (int i = lx; i <= hx; i++)
					if (query(i, mid, 1) > v)
						v = query(i, mid, 1), p = i;
				if (v > big) {
					big = v;
					if (query(p, mid+1, 1) > v)
						ly = mid+1, by = mid+1;
					else
						hy = mid, by = mid;
					bx = p;
				}
				else {
					if (mid >= by)
						hy = mid;
					else
						ly = mid+1;
				}
			}

		}
		guess(lx, ly, 1);
		return 0;
	}

	int x, y, z, v;
	x = y = z = v = 0;
	for (int i = 0; i < Q/3; i++) {
		int nx = ran(N);
		int ny = ran(M);
		int nz = ran(K);
		int nv = query(nx, ny, nz);
		if (nv > v) {
			v = nv;
			x = nx;
			y = ny;
			z = nz;
		}
	}
	while (true) {
		int nv;
		if (x < N) {
			nv = query(x+1, y, z);
			if (nv > v) {
				v = nv;
				x++;
				continue;
			}
		}
		if (y < M) {
			nv = query(x, y+1, z);
			if (nv > v) {
				v = nv;
				y++;
				continue;
			}
		}
		if (z < K) {
			nv = query(x, y, z+1);
			if (nv > v) {
				v = nv; z++;continue;
			}
		}
		if (x > 1) {
			nv = query(x-1, y, z);
			if (nv > v) {
				v = nv; x--;continue;
			}
		}
		if (y > 1) {
			nv = query(x, y-1, z);
			if (nv > v) {
				v = nv; y--;continue;
			}
		}
		if (z > 1) {
			nv = query(x, y, z-1);
			if (nv > v) {
				v = nv; z--;continue;
			}
		}
		break;
	}
	guess(x, y, z);
}
