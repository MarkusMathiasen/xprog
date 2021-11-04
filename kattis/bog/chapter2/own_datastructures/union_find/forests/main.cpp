#include <bits/stdc++.h>
using namespace std;

int p, t;

int main() {
	scanf("%d%d", &p, &t);
	vector<set<int>> list(p, set<int>());
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		a--; b--;
		list[a].insert(b);
	}
	set<set<int>> res;
	for (auto& x : list)
		res.insert(x);
	printf("%ld\n", res.size());
}
