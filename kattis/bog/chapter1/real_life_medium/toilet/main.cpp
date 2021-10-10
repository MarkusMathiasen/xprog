#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	char pos = s[0];
	int res = 0;
	for (int i = 1; i < s.size(); i++) {
		res += pos != s[i];
		res += (s[i] == 'D');
		pos = 'U';
	}
	printf("%d\n", res);
	res = 0;
	pos = s[0];
	for (int i = 1; i < s.size(); i++) {
		res += pos != s[i];
		res += s[i] == 'U';
		pos = 'D';
	}
	printf("%d\n", res);
	res = 0;
	pos = s[0];
	for (int i = 1; i < s.size(); i++) {
		res += pos != s[i];
		pos = s[i];
	}
	printf("%d\n", res);
}
