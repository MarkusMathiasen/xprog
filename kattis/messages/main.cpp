#include <bits/stdc++.h>
using namespace std;

set<string> dic;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> s, s != "#")
		dic.insert(s);
	string s2;
	while (cin >> s2, s2 != "#") {
		s += s2;
		if (s.back() != '|')
			continue;
		s.pop_back();
		int maxi = s.size();
		int res = 0;
		for (int i = s.size()-1; i >= 0; i--)
			for (string w : dic)
				if ((int)w.size()+i <= maxi && s.substr(i, w.size()) == w)
					res++, maxi = i;
		printf("%d\n", res);
		s = "";
	}
}
