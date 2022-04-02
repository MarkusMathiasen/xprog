#include <bits/stdc++.h>
using namespace std;

struct op {
	bool on;
	int sx, ex;
	int sy, ey;
	int sz, ez;
	op(bool on, int sx, int ex, int sy, int ey, int sz, int ez) :
			on(on), sx(sx), ex(ex), sy(sy), ey(ey), sz(sz), ez(ez) {}
};

int main() {
	vector<op> ops;
	map<long long, long long> toIdx, toIdy, toIdz, fromIdx, fromIdy, fromIdz;
	set<long long> x_er, y_er, z_er;
	string on(3, ' '); int sx, ex, sy, ey, sz, ez;
	while (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d", &on[0], &sx, &ex, &sy, &ey, &sz, &ez) != EOF) {
		ops.push_back(op(on[1] == 'n', sx, ex+1, sy, ey+1, sz, ez+1));
		x_er.insert(sx);
		x_er.insert(ex+1);
		y_er.insert(sy);
		y_er.insert(ey+1);
		z_er.insert(sz);
		z_er.insert(ez+1);
	}
	int cnt = 0;
	for (int x : x_er)
		toIdx[x] = cnt,
		fromIdx[cnt++] = x;
	cnt = 0;
	for (int y : y_er)
		toIdy[y] = cnt,
		fromIdy[cnt++] = y;
	cnt = 0;
	for (int z : z_er)
		toIdz[z] = cnt,
		fromIdz[cnt++] = z;
	vector<vector<vector<bool>>> grid(x_er.size(), vector<vector<bool>>(y_er.size(), vector<bool>(z_er.size(), 0)));
	for (auto& o : ops)
		for (int x = toIdx[o.sx]; x < toIdx[o.ex]; x++)
			for (int y = toIdy[o.sy]; y < toIdy[o.ey]; y++)
				for (int z = toIdz[o.sz]; z < toIdz[o.ez]; z++)
					grid[x][y][z] = o.on;
	long long res = 0;
	for (int x = 0; x < (int)x_er.size()-1; x++)
		for (int y = 0; y < (int)y_er.size()-1; y++)
			for (int z = 0; z < (int)z_er.size()-1; z++)
				res += grid[x][y][z] ? (fromIdx[x+1]-fromIdx[x])*(fromIdy[y+1]-fromIdy[y])*(fromIdz[z+1]-fromIdz[z]) : 0;
	printf("%lld\n", res);
}
