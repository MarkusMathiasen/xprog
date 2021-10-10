#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	vector<string> lines = {".", ".", "#", ".", "."};
	for (int i = 0; i < (int)s.size(); i++) {
		string c = i%3 == 2 ? "*" : "#";
		if (c == "*")
			lines[2].back() = c[0];
		lines[0] += "." + c + "..";
		lines[1] += c + "." + c + ".";
		string l(1, s[i]);
		lines[2] += "." + l + "." + c;
		lines[3] += c + "." + c + ".";
		lines[4] += "." + c + "..";
	}
	for (int i = 0; i < 5; i++)
		cout << lines[i] << endl;
}
