#include <bits/stdc++.h>
using namespace std;

int main() {
	set<string> words;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	bool dup = false;
	while (cin >> s) {
		dup |= words.count(s);
		words.insert(s);
	}
	printf(!dup ? "yes\n" : "no\n");
}
