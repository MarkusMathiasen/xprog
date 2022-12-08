#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string, int> w;
unordered_map<string, vector<string>> graph;

void compute_w(string v) {
	for (string& u : graph[v])
		compute_w(u),
		w[v] += w[u];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	string line, dir = "";
	getline(cin, line);
	while (sz(line)) {
		stringstream ss(line);
		string cmd, arg; ss >> cmd >> cmd;
		if (cmd == "cd") {
			ss >> arg;
			if (arg == "..") {
				dir.pop_back();
				while (dir.back() != '/')
					dir.pop_back();
			} else
				dir += sz(dir) ? arg + "/" : arg;
		} else if (cmd == "ls") {
			bool update = !w[dir];
			while (getline(cin, line), sz(line) && line[0] != '$') {
				if (update) {
					stringstream s2(line);
					string a, b; s2 >> a >> b;
					if (a == "dir")
						graph[dir].push_back(dir + b + "/");
					else
						w[dir] += stoi(a);
				}
			}
			continue;
		} else assert(false);
		getline(cin, line);
	}
	int res = 1e9;
	compute_w("/");
	for (auto& [k,v] : w)
		if (w["/"] - v <= 40000000)
			res = min(res, v);
	printf("%d\n", res);
}
