#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p; scanf("%d%d", &n, &p);
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, p*(i+1) + v[0] - v[i]);
	printf("%d\n", res);
}
