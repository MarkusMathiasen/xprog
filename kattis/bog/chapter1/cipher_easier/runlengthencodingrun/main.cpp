#include <bits/stdc++.h>
using namespace std;

string op, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> op >> s;
	if (op == "D") {
		stringstream ss(s);
		char c; int d;
		while (ss >> c >> d)
			for (int i = 0; i < d; i++)
				printf("%c", c);
		printf("\n");
	}
	else {
		int am = 0;
		char prev = s[0];
		for (char c : s) {
			if (c == prev)
				am++;
			else {
				printf("%c%d", prev, am);
				am = 1;
				prev = c;
			}
		}
		printf("%c%d\n", prev, am);
	}
}
