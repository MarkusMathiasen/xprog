#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	unordered_map<string, int> m;
	while (getline(cin, line) && line != "") {
		stringstream ss(line);
		string cmd; ss >> cmd;
		if (cmd == "def") {
			string w; int v; ss >> w >> v;
			m[w] = v;
		}
		else if (cmd == "calc") {
			string w, op, preop = "+";
			bool known = true;
			int res = 0;
			while (ss >> w >> op) {
				known &= m.count(w);
				if (known)
					res += preop == "+" ? m[w] : -m[w];
				preop = op;
				printf("%s %s ", w.c_str(), op.c_str());
			}
			if (known) {
				string wres = "";
				for (auto& [k,v] : m)
					if (v == res)
						wres = k;
				if (wres != "")
					printf("%s\n", wres.c_str());
				else
					printf("unknown\n");
			}
			else
				printf("unknown\n");
		}
		else if (cmd == "clear")
			m.clear();
		else
			throw cmd;
	}
}
