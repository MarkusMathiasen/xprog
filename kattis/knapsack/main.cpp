#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int c, n;
	while (scanf("%d%d", &c, &n) != EOF) {
		vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
		vector<vector<ii>> prev(n+1, vector<ii>(c+1, ii(n, 0)));
		vector<ii> items(n, ii());
		for (int i = 0; i < n; i++)
			scanf("%d%d", &items[i].first, &items[i].second); //value, weight
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j <= c; j++) {
				if (j < items[i].second) {
					dp[i][j] = dp[i+1][j];
					prev[i][j] = ii(i+1, j);
				}
				else {
					int dont = dp[i+1][j];
					int does = dp[i+1][j-items[i].second]+items[i].first;
					if (dont < does) {
						dp[i][j] = does;
						prev[i][j] = ii(i+1, j-items[i].second);
					}
					else {
						dp[i][j] = dont;
						prev[i][j] = ii(i+1, j);
					}
				}
			}
		}
		int res = 0;
		vector<int> resItems;
		int init = 0;
		for (int i = 0; i <= c; i++)
			if (dp[0][init] < dp[0][i])
				init = i;
		for (int i = 0; i < n; i++) {
			if (prev[i][init].second != init) {
				init = prev[i][init].second;
				resItems.push_back(i);
				res++;
			}
		}
		printf("%d\n", res);
		for (int x : resItems)
			printf("%d ", x);
		printf("\n");
	}
}
