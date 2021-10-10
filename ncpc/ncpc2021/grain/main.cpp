#include <bits/stdc++.h>
using namespace std;

struct rect {
	double x;
	double y;
	double x2;
	double y2;
};

double area(rect r) {
	return (r.x2-r.x)*(r.y2-r.y);
}

int main() {
	int n; scanf("%d", &n);
	vector<vector<rect>> A(10, vector<rect>());
	for (int i = 0; i < n; i++) {
		int x, y, r; scanf("%d%d%d", &x, &y, &r);
		A[0].push_back(rect());
		double len = sqrt(r*r*3.14159265);
		A[0][i].x = x-len/2;
		A[0][i].y = y-len/2;
		A[0][i].x2 = x+len/2;
		A[0][i].y2 = y+len/2;
	}
	for (int i = 0; i < n; i++) {
		rect curr = A[0][i];
		for (int r = i-1; r >= 0; r--) {
			for (int c = 0; c < (int)A[r].size(); c++) {
				if (r == 0 && i == c)
					break; // dont consider circles we have not calculated intersections for
				rect other = A[r][c];
				rect newRect;
				newRect.x = max(curr.x, other.x);
				newRect.y = max(curr.y, other.y);
				newRect.x2 = min(curr.x2, other.x2);
				newRect.y2 = min(curr.y2, other.y2);
				if (newRect.x >= newRect.x2 || newRect.y >= newRect.y2)
					continue; // No intersection
				A[r+1].push_back(newRect);
			}
		}
	}
	double res = 0;
	for (int r = 0; r < 10; r++)
		for (rect x : A[r])
			if (r%2 == 0)
				res += area(x);
			else
				res -= area(x);
	printf("%lf\n", res);
}
