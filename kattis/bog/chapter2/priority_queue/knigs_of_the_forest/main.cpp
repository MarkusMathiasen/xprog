#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int k, n; scanf("%d%d", &k, &n);
	int y, s; scanf("%d%d", &y, &s);
	priority_queue<int> Q;
	vector<ii> mooses;
	for (int i = 0; i < n+k-2; i++) {
		int year, str; scanf("%d%d", &year, &str);
		mooses.push_back(ii(year, str));
	}
	mooses.push_back(ii(y, s));
	sort(mooses.begin(), mooses.end());
	int pos;
	for (pos = 0; mooses[pos].first == 2011; pos++)
		Q.push(mooses[pos].second);
	bool possible = true;
	for (pos = pos; true; pos++) {
		int ws = Q.top();
		if (ws == s)
			break;
		Q.pop();
		if (pos == (int)mooses.size()) {
			possible = false;
			break;
		}
		Q.push(mooses[pos].second);
	}
	if (possible)
		printf("%d\n", 2011+pos-k);
	else
		printf("unknown\n");
}
