#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> words;
	set<string> comp;
	string s;
	while (cin >> s)
		words.insert(s);
	for (string x : words)
		for (string y : words)
			if (x != y)
				comp.insert(x + y);
	for (string x : comp)
		printf("%s\n", x.c_str());
}
