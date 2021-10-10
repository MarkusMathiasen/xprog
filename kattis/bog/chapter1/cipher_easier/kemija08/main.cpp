#include <bits/stdc++.h>
using namespace std;

string s, res = "", v = "aeiou";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, s);
	for (int i = 0; i < (int)s.size(); i++) {
		printf("%c", s[i]);
		if (v.find(s[i]) != string::npos)
			i += 2;
	}
	printf("\n");
}
