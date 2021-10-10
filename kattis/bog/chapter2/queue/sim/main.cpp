#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	string s; getline(cin, s);
	while (t--) {
		getline(cin, s);
		list<char> l;
		list<char>::iterator pos = l.begin();
		for (char c : s) {
			if (c == '[')
				pos = l.begin();
			else if (c == ']')
				pos = l.end();
			else if (c == '<') {
				if (pos != l.begin())
					pos--, pos = l.erase(pos);
			}
			else
				l.insert(pos, c);
		}
		for (char c : l)
			printf("%c", c);
		printf("\n");
	}
}
