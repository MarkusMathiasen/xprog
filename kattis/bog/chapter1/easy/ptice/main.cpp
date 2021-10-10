#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>

int n;
string s;
is p[3];

char a(int x) {
	return (x%3)+ 'A';
}
char b(int x) {
	if (x%2 == 0)
		return 'B';
	if (x%4 == 1)
		return 'A';
	return 'C';
}
char c(int x) {
	if (x%6 == 0 || x%6 == 1)
		return 'C';
	if (x%6 == 2 || x%6 == 3)
		return 'A';
	return 'B';
}

int main() {
	p[0] = is(0, "Adrian");
	p[1] = is(0, "Bruno");
	p[2] = is(0, "Goran");
	cin >> n >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		char x = s[i];
		if (a(i) == x)
			p[0].first++;
		if (b(i) == x)
			p[1].first++;
		if (c(i) == x)
			p[2].first++;
	}
	sort(p, p+3);
	cout << p[2].first << endl;
	if (p[0].first == p[2].first)
		cout << p[0].second << endl;
	if (p[1].first == p[2].first)
		cout << p[1].second << endl;
	cout << p[2].second << endl;
}
