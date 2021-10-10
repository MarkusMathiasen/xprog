#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; getline(cin, s);
	for (int i = 0; i < (int)s.size()-1; i++) {
		string s1 = s.substr(i, 2), s2 = "";
		if (i < (int)s.size()-2)
			s2 = s.substr(i, 3);
		if (s1 == ":)" || s1 == ";)" || s2 == ":-)" || s2 == ";-)")
			printf("%d\n", i);
	}
}
