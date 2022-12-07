#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string, vector<string>> graph;
unordered_map<string, ll> w;

ll update_w(string v) {
	for (string& u : graph[v]) {
		w[v] += update_w(u);
	}
	return w[v];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	string line;
	string dir = "";
	getline(cin, line);
	while (line != "") {
		stringstream ss(line);
		string dollar, cmd;
		ss >> dollar >> cmd;
		if (cmd == "ls") {
			ll sum = 0;
			getline(cin, line);
			while (sz(line) > 0 && line[0] != '$') {
				stringstream s2(line);
				string a, b; s2 >> a >> b;
				if (a == "dir") {
					graph[dir].push_back(dir + b + "/");
				} else {
					sum += stoll(a);
				}
				getline(cin, line);
			}
			w[dir] = sum;
		} else if (cmd == "cd") {
			string d; ss >> d;
			if (d == "..") {
				dir.pop_back();
				while (dir.back() != '/')
					dir.pop_back();
			} else
				dir += (d == "/" ? "" : d) + "/";
			getline(cin, line);
		} else assert(false);
	}
	update_w("/");
	ll res = 1e18;
	ll target = 30000000 - (70000000 - w["/"]);
	for (auto& [v,d] : w)
		if (d >= target)
			res = min(res, d);
	printf("%lld\n", res);
}
