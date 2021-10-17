#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, int> def;
	string line;
	while (getline(cin, line), line != "") {
		stringstream ss(line);
		string cmd; ss >> cmd;
		if (cmd == "define") {
			int x; string s; ss >> x >> s;
			def[s] = x;
		}
		else if (cmd == "eval") {
			string a, b, c; ss >> a >> c >> b;
			if (!def.count(a) || !def.count(b)) {
				printf("undefined\n");
				continue;
			}
			if (c == "<")
				printf(def[a] < def[b] ? "true\n" : "false\n");
			else if (c == ">")
				printf(def[a] > def[b] ? "true\n" : "false\n");
			else if (c == "=")
				printf(def[a] == def[b] ? "true\n" : "false\n");
			else throw c;
		}
		else throw cmd;
	}
}
