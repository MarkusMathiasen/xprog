#include <bits/stdc++.h>
using namespace std;

string format(string& s) {
	for (char& c : s) {
		if (c == '-')
			c = ' ';
		else
			c = tolower(c);
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	string s; getline(cin, s);
	set<string> keywords;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		keywords.insert(format(s));
	}
	printf("%d\n", (int)keywords.size());
}
