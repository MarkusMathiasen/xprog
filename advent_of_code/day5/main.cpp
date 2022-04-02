#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

struct line {
	int x1, y1;
	int x2, y2;
};

vector<line> lines;

int main() {
	line l;
	while (scanf("%d,%d -> %d,%d", &l.x1, &l.y1, &l.x2, &l.y2) != EOF)
		lines.push_back(l);
	map<ii, int> m;
	for (line& x : lines)
		if (x.y1 == x.y2)
			for (int i = min(x.x1, x.x2); i <= max(x.x1, x.x2); i++)
				m[ii(i, x.y1)]++;
		else if (x.x1 == x.x2)
			for (int i = min(x.y1, x.y2); i <= max(x.y1, x.y2); i++)
				m[ii(x.x1, i)]++;
		else if (x.x1 + x.y1 == x.x2 + x.y2)
			for (int i = 0; i <= max(x.x1, x.x2)-min(x.x1, x.x2); i++)
				m[ii(min(x.x1, x.x2)+i, max(x.y1, x.y2)-i)]++;
		else if (x.x1 - x.y1 == x.x2 - x.y2)
			for (int i = 0; i <= max(x.x1, x.x2)-min(x.x1, x.x2); i++)
				m[ii(min(x.x1, x.x2)+i, min(x.y1, x.y2)+i)]++;
		else assert(false);
	int res = 0;
	for (auto& [p,x] : m)
		res += x >= 2;
	printf("%d\n", res);
}
