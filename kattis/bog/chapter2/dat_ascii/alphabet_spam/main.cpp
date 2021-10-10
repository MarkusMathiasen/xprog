#include <bits/stdc++.h>
using namespace std;

int main() {
	int lower = 0, upper = 0, white = 0, symbol = 0;
	string s; cin >> s;
	for (char c : s) {
		if (c == '_')
			white++;
		else if (!isalpha(c))
			symbol++;
		else if (islower(c))
			lower++;
		else
			upper++;
	}
	double n = s.size();
	printf("%lf\n%lf\n%lf\n%lf\n", white/n, lower/n, upper/n, symbol/n);
}
