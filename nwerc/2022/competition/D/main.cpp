#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<int> vi;


int h, w;
vector<string> graph;
vector<vector<pdd>> dist;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> h >> w;
	graph.assign(h, "");
	rep(i, 0, h) cin >> graph[i];
	dist.assign(h+1, vector<pdd>(w+1, pdd(1e300, 1e300)));
	dist[0][0] = pdd(5, 5);
	rep(i, 0, h+1) rep(j, 0, w+1) {
		if (i < h)
			dist[i+1][j].first = min(dist[i][j].first+10, dist[i+1][j].first);
		if (j < w)
			dist[i][j+1].second = min(dist[i][j].second+10, dist[i][j+1].second);
		if (i < h && j < w) {
			double d = graph[i][j] == 'O' ? M_PI*2.5 : 10;
			dist[i][j+1].first = min(dist[i][j].second+d, dist[i][j+1].first);
			dist[i+1][j].second = min(dist[i][j].first+d, dist[i+1][j].second);
		}
	}
	printf("%lf\n", min(dist[h][w-1].second, dist[h-1][w].first)+5);
}
