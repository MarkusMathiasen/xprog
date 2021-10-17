#include <bits/stdc++.h>
using namespace std;

char conv(char c) {
	if (c <= 'c')
		return '2';
	if (c <= 'f')
		return '3';
	if (c <= 'i')
		return '4';
	if (c <= 'l')
		return '5';
	if (c <= 'o')
		return '6';
	if (c <= 's')
		return '7';
	if (c <= 'v')
		return '8';
	return '9';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_map<string, int> dic;
	while (n--) {
		string s; cin >> s;
		for (char& c : s)
			c = conv(c);
		dic[s]++;
	}
	string num; cin >> num;
	printf("%d\n", dic[num]);
}
