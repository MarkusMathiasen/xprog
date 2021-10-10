#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<int, int>
#define lii pair<ll, ii>

struct path{
	ll minPrice;
	ll c;
	int minFlights;
	int maxFlights;

};

vector<path> dp;
vector<vector<ii>> graph;
int n, m;
int mod = (int) 1e9+7;

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n+1, vector<ii>());
	while (m--){
		int a, b; ll c; scanf("%d %d %lld", &a, &b, &c);
		graph[a].push_back(ii(c, b));
	}
	dp.assign(n+1, {-1, 0, 0, 0});
	dp[0] = {0, 1, -1, -1};
	graph[0].push_back(ii(0, 1));
	priority_queue<lii, vector<lii>, greater<lii>> Q;
	Q.push(lii(0, ii(0, 1)));
	while(!Q.empty()){
		ll d = Q.top().first;
		int to = Q.top().second.second;
		int from = Q.top().second.first;
		Q.pop();
		if (d == dp[to].minPrice){
			dp[to].c += dp[from].c;
			if (dp[to].c >= mod) dp[to].c -= mod;
			dp[to].minFlights = min(dp[to].minFlights, dp[from].minFlights+1);
			dp[to].maxFlights = max(dp[to].maxFlights, dp[from].maxFlights+1);
			continue;
		}
		else if (dp[to].minPrice != -1) continue;
		else {
			dp[to].minPrice = d;
			dp[to].c = dp[from].c;
			dp[to].minFlights = dp[from].minFlights+1;
			dp[to].maxFlights = dp[from].maxFlights+1;
		}
		for (int i = 0; i < graph[to].size(); i++){
			int nex = graph[to][i].second;
			ll nd = graph[to][i].first+d;
			Q.push(lii(nd, ii(to, nex)));
		}
	}
	printf("%lld %lld %d %d", dp[n].minPrice, dp[n].c, dp[n].minFlights, dp[n].maxFlights);
}
