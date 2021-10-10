#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<int> costs(4, 0);
vector<ii> tim(3, ii(0, 0));
int res = 0;

int main() {
	scanf("%d%d%d", &costs[1], &costs[2], &costs[3]);
	for (int i = 0; i < 3; i++)
		scanf("%d%d", &tim[i].first, &tim[i].second);
	for (int t = 1; t <= 100; t++) {
		int am = 0;
		for (int i = 0; i < 3; i++)
			if (tim[i].first <= t && t < tim[i].second)
				am++;
		res += am*costs[am];
	}
	printf("%d\n", res);
}
