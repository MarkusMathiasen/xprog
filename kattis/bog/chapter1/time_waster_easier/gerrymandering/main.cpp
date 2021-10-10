#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int P, D;

int main() {
	scanf("%d%d", &P, &D);
	vector<ii> disVotes(D, ii(0, 0));
	for (int i = 0; i < P; i++) {
		int d, a, b; scanf("%d%d%d", &d, &a, &b); d--;
		disVotes[d].first += a;
		disVotes[d].second += b;
	}
	int wa = 0, wb = 0, tot = 0;
	for (ii p : disVotes) {
		int a = p.first, b = p.second;
		tot += a+b;
		int aa, bb;
		if (a < b)
			aa = a, bb = b-((a+b)/2+1);
		else
			bb = b, aa = a-((a+b)/2+1);
		printf("%c %d %d\n", a > b ? 'A' : 'B', aa, bb);
		wa += aa, wb += bb;
	}
	printf("%lf\n", abs(wa-wb)/(double)tot);
}
