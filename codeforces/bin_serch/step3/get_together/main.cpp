#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n;
vector<ii> p;

double le(double t) {
	double res = -2e9;
	for (ii x : p)
		res = max(res, (x.first - x.second*t));
	return res;
}
double ri(double t) {
	double res = 2e9;
	for (ii x : p)
		res = min(res, (x.first + x.second*t));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	p.assign(n, ii(0, 0));
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	double low = 0;
	double high = 2e9;
	while (low + 1e-7 < high) {
		double mid = (low + high) / 2;
		if (le(mid) <= ri(mid))
			high = mid;
		else
			low = mid;
	}
	printf("%f\n", low);
}
