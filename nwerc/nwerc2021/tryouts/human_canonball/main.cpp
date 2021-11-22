#include <bits/stdc++.h>
using namespace std;
#define dd pair<double, double>
#define id pair<int, double>

double geoDist(dd a, dd b) {
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int  main() {
	dd start; cin >> start.first >> start.second;
	dd slut; cin >> slut.first >> slut.second;
	int n; cin >> n;
	vector<dd> points(n+2, dd());
	points[0] = start;
	points[n+1] = slut;
	for (int i = 1; i <= n; i++)
		cin >> points[i].first >> points[i].second;
	vector<vector<double>> adjMat(n+2, vector<double>(n+2, 0));
	for (int i = 0; i < n+2; i++) {
		for (int j = 0; j < n+2; j++) {
			if (i == j)
				continue;
			double gDist = geoDist(points[i], points[j]);
			if (i != 0 && i != n+1) {
				double canonDist = abs(gDist-50);
				adjMat[i][j] = min(gDist/5, canonDist/5+2);
			}
			else
				adjMat[i][j] = gDist/5;
		}
	}
	vector<vector<double>> dist = adjMat;
	for (int k = 0; k < n+2; k++)
		for (int i = 0; i < n+2; i++)
			for (int j = 0; j < n+2; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	printf("%lf\n", dist[0][n+1]);
}
