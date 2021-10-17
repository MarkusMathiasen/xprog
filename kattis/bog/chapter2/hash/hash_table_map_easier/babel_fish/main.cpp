#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	unordered_map<string, string> dict;
	while (getline(cin, line), line != "") {
		stringstream ss(line);
		string k, v; ss >> v >> k;
		dict[k] = v;
	}
	while (cin >> line) {
		if (dict.count(line))
			cout << dict[line] << "\n";
		else
			cout << "eh\n";
	}
}
