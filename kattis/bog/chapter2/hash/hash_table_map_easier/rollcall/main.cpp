#include <bits/stdc++.h>
using namespace std;
#define ss pair<string, string>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, int> nameCount;
	set<ss> names;
	string fn, ln;
	while (cin >> fn >> ln) {
		names.insert(ss(ln, fn));
		nameCount[fn]++;
	}
	for (auto& [l,f] : names)
		if (nameCount[f] > 1)
			printf("%s %s\n", f.c_str(), l.c_str());
		else
			printf("%s\n", f.c_str());
}
