#include <bits/stdc++.h>
using namespace std;

int sx, ex, sy, ey; 

bool shoot(int x, int y, int vx, int vy) {
	if (x > ex || y < sy)
		return false;
	if (x >= sx && x <= ex && y >= sy && y <= ey)
		return true;
	x += vx;
	y += vy;
	vx = max(0, vx-1);
	vy--;
	return shoot(x, y, vx, vy);
}

int main() {
	scanf("target area: x=%d..%d, y=%d..%d", &sx, &ex, &sy, &ey);
	int res = 0;
	for (int vx = 0; vx <= 300; vx++) {
		for (int vy = 1000; vy >= -1000; vy--) {
			res += shoot(0, 0, vx, vy);
		}
	}
	printf("%d\n", res);
}
