#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, n; cin >> p >> n;
	set<string> s;
	int day = 0;
	string part;
	for (int i = 1; i <= n; i++) {
		cin >> part;
		s.insert(part);
		if ((int)s.size() == p) {
			day = i;
			break;
		}
	}
	if (day)
		printf("%d\n", day);
	else
		printf("paradox avoided\n");
}
