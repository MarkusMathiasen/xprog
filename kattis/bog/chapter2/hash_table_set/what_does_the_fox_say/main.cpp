#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		string sounds;
		getline(cin, sounds); getline(cin, sounds);
		string b, c;
		unordered_set<string> known;
		while (cin >> b >> b >> c, b == "goes")
			known.insert(c);
		stringstream ss(sounds);
		while (ss >> b) {
			if (!known.count(b))
				printf("%s ", b.c_str());
		}
		printf("\n");
	}
}
