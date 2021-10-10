#include <bits/stdc++.h>
using namespace std;

int main() {
	multiset<string> m;
	string s; cin >> s;
	for (int i = 0; i < (int)s.size(); i += (int)s.size()/3)
		m.insert(s.substr(i, s.size()/3));
	for (string w : m)
		if (m.count(w) >= 2) {
			cout << w << endl;
			return 0;
		}
}
