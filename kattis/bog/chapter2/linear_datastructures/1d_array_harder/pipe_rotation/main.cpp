#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<bool> prev(m, false);
	bool last = false;
	bool possible = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (j == 0)
				possible &= !last;
			char c; scanf(" %c", &c);
			if (c == 'A') {
				possible &= !prev[j];
				possible &= !last;
				last = prev[j] = false;
			}
			else if (c == 'B')
				possible &= last ^ prev[j];
			else if (c == 'C') {
				if (prev[j] && last)
					prev[j] = last = false;
				else {
					prev[j] = !prev[j];
					last = !last;
				}
			}
			else if (c == 'D')
				possible &= last && prev[j];
			else
				throw c;
		}
	possible &= !last;
	for (bool b : prev)
		possible &= !b;
	printf(possible ? "Possible\n" : "Impossible\n");
}
