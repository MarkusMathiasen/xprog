#include <bits/stdc++.h>
using namespace std;

int am;
string s;

void shift(char& c) {
	if (c == '.')
		c = 27;
	else if (c == '_')
		c = 26;
	else
		c -= 'A';
	c += am;
	c %= 28;
	if (c == 27)
		c = '.';
	else if (c == 26)
		c = '_';
	else
		c += 'A';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> am >> s) {
		reverse(s.begin(), s.end());
		for (char& c : s)
			shift(c);
		cout << s << endl;
	}
}
