#include <bits/stdc++.h>
using namespace std;

string stolow(string s) {
	for (char& c : s)
		c = tolower(c);
	return s;
}

set<string> seen;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (getline(cin, s), s != "") {
		stringstream ss(s);
		while (ss >> s) {
			if (seen.count(stolow(s)))
				printf(". ");
			else {
				printf("%s ", s.c_str());
				seen.insert(stolow(s));
			}
		}
		printf("\n");
	}
}
