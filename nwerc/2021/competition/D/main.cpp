#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int n; scanf("%d", &n);
	vector<ii> stars(n, ii());
	for (int i = 0; i < n; i++)
		scanf("%d%d", &stars[i].first, &stars[i].second);
	if (n == 1) {
		printf("%d\n", 4);
		return 0;
	}
	int min1 = 1e7, max1 = -1e7, min2 = 1e7, max2 = -1e7;
	int d1 = stars[0].first + stars[0].second;
	int d2 = stars[0].first - stars[0].second;
	bool dia1 = true;
	bool dia2 = true;
	for (auto& [x,y] : stars)
		dia1 &= x+y == d1,
		dia2 &= x-y == d2,
		min1 = min(x+y, min1),
		min2 = min(x-y, min2),
		max1 = max(x+y, max1),
		max2 = max(x-y, max2);
	int res = max1-min1 + max2-min2 + 4 + (dia1 || dia2);
	printf("%d\n", res);
}
