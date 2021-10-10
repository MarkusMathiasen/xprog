#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	getline(cin, line);
	while (true) {
		vector<string> v;
		do {
			v.push_back(line);
		} while (getline(cin, line), line != "");
		sort(v.begin(), v.end(), [](string const& a, string const& b) {
			int as = a.size(), bs = b.size();
			for (int i = 0; i < as; i++) {
				if (i == bs)
					return false;
				if (a[as-i-1] != b[bs-i-1])
					return a[as-i-1] < b[bs-i-1];
			}
			return a.size() < b.size();
		});
		int len = 0;
		for (string s : v)
			len = max(len, (int)s.size());
		for (string s : v)
			printf("%*s\n", len, s.c_str());
		if (getline(cin, line))
			printf("\n");
		else
			break;
	}
}
