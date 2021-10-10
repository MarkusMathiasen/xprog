#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int n, m, k;
vector<ii> crit;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	crit.assign(n, ii(0, 0));
	for (int i = 0; i < n; i++) {
		scanf("%d", &crit[i].first);
		crit[i].second = i+1;
	}
	bool pos = true;
	if (k % m != 0)
		pos = false;
	
	sort(crit.begin(), crit.end());
	int bad = n - k / m - 1;
	int good = bad+2;
	double rateSum = m;
	double raters = 1;
	if (k == 0) {
		cout << "impossible" << endl;
		return 0;
	}
	vector<int> res(1, crit[good-1].second);

	while (bad >= 0 || good < n) {
		if (bad >= 0 && rateSum / raters > crit[bad].first) {
			res.push_back(crit[bad].second);
			raters++;
			bad--;
		}
		else if (good < n && rateSum / raters <= crit[good].first) {
			res.push_back(crit[good].second);
			raters++;
			rateSum += m;
			good++;
		}
		else {
			pos = false;
			break;
		}
	}
	if (!pos) {
		printf("impossible\n");
		return 0;
	}
	for (int i : res)
		printf("%d ", i);
	printf("\n");
}
