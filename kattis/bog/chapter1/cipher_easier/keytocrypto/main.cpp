#include <bits/stdc++.h>
using namespace std;

string s, k;

void shift(char& c, char& k) {
	k -= 'A';
	c -= 'A';
	c += 26-k;
	c %= 26;
	c += 'A';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> k;
	for (int i = 0; i < (int)s.size(); i++) {
		shift(s[i], k[i]);
		k.push_back(s[i]);
	}
	cout << s << endl;
}
