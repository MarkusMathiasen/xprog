#include <bits/stdc++.h>
using namespace std;
#define ll long long

int c, n, m;
vector<ll> farms; // number of farms with 'i' cows
vector<ll> res(51, 0);

int main() {
	scanf("%d%d%d", &c, &n, &m);
	farms.assign(1001, 0);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		farms[x]++;
	}
	for (int d = 0; d <= 50; d++) {
		for (int i = 0; i <= c; i++)
			res[d] += farms[i];
		vector<ll> nfarms(1001, 0);
		for (int i = 0; i <= c; i++) {
			if (i*2 <= c)
				nfarms[i*2] += farms[i];
			else
				nfarms[i] += farms[i]*2;
		}
		farms = nfarms;
	}
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		printf("%lld\n", res[x]);
	}
}
