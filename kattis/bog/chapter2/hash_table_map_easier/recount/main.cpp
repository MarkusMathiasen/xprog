#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, int> m;
	string s;
	string res = "Runoff!";
	int am = 0;
	while (getline(cin, s), s != "***") {
		m[s]++;
		if (m[s] > am)
			am = m[s], res = s;
		else if (m[s] == am)
			res = "Runoff!";
	}
	printf("%s\n", res.c_str());
}
