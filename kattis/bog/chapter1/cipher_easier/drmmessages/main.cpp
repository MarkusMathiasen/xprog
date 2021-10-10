#include <bits/stdc++.h>
using namespace std;

string s, a, b;

void shift(char& c, int n) {
	c -= 'A';
	c += n;
	c %= 26;
	c += 'A';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	int n = s.size()/2;
	a = s.substr(0, n);
	b = s.substr(n, n);
	int an = 0;
	for (char c : a)
		an += c - 'A';
	for (char& c : a)
		shift(c, an%26);
	int bn = 0;
	for (char c : b)
		bn += c - 'A';
	for (char& c : b)
		shift(c, bn%26);
	for (int i = 0; i < n; i++)
		shift(a[i], b[i] - 'A');
	cout << a << endl;
}
