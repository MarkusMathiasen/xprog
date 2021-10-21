#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	while (cin >> n && n) {
		string s; getline(cin, s);
		map<string, int> m;
		while (n--) {
			getline(cin, s);
			stringstream ss(s);
			while (ss >> s)
				continue;
			for (char& c : s)
				c = tolower(c);
			m[s]++;
		}
		printf("List %d:\n", ++cnt);
		for (auto& [k,v] : m)
			printf("%s | %d\n", k.c_str(), v);
	}
}
