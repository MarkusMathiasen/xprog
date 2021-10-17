#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, p; scanf("%d%d%d", &n, &m, &p);
	vector<int> front(n, 0), back(m, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &front[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &back[i]);
	vector<double> gears;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			gears.push_back((double)back[j] / front[i]);
	sort(gears.begin(), gears.end());
	bool res = true;
	for (int i = 1; i < (int)gears.size(); i++)
		res &= gears[i] <= gears[i-1]*(p+100)/100;
	printf(res ? "Ride on!\n" : "Time to change gears!\n");
}
