#include <bits/stdc++.h>
using namespace std;

set<char> solved;
map<char, int> pen;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; char p; string s;
	while (cin >> t >> p >> s) {
		if (solved.count(p))
			continue;
		if (s == "wrong")
			pen[p] += 20;
		else {
			pen[p] += t;
			solved.insert(p);
		}
	}
	int res = 0;
	for (char p : solved)
		res += pen[p];
	printf("%d %d\n", (int)solved.size(), res);
}
