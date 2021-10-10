#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> pats;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n) {
		pats.assign(n, "");
		getline(cin, s);
		for (int i = 0; i < n; i++)
			getline(cin, pats[i]);
		getline(cin, s);
		for (string p : pats) {
			for (int i = 0; i < s.size()-p.size()+1; i++)
				if (s.substr(i, p.size()) == p)
					printf("%d ", i);
			printf("\n");
		}
	}
}
