#include <bits/stdc++.h>
using namespace std;

int t;
string s;
vector<string> nodes = {
	"DEFGAB",
	"cdefgabDEFGAB",
	"cdefgaCDEFGA",
	"cdefgDEFG",
	"",
	"",
	"cdefDEF",
	"cdeDE",
	"cdD",
	"c"
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	getline(cin, s);
	while (getline(cin, s), t--) {
		for (int f = 0; f < 10; f++) {
			bool fState = false;
			int presses = 0;
			for (char c : s) {
				if (nodes[f].find(c) == string::npos)
					fState = false;
				else {
					presses += !fState;
					fState = true;
				}
			}
			if (presses > (int)(s.size()+1)/2)
				throw 1;
			printf("%d ", presses);
		}
		printf("\n");
	}
}
