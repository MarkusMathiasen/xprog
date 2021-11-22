#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int n; scanf("%d", &n);
	vector<ii> byX, byY;
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		byX.push_back(ii(x, y));
		byY.push_back(ii(x, y));
	}
	sort(byX.begin(), byX.end());
	sort(byY.begin(), byY.end(), [](const ii& a, const ii& b){
		if (a.second != b.second)
			return a.second < b.second;
		return a.first < b.first;
	});
	int res = 0;

}
