#include <bits/stdc++.h>
using namespace std;

map<string, int> vis;
map<string, vector<string>> graph;
bool twice = false;

int dfs(string x) {
	if (islower(x[0])) {
		if (x == "end")
			return 1;
		else if (!vis[x])
			vis[x]++;
		else if (vis[x] && twice)
			return 0;
		else if (vis[x] && !twice && x != "start")
			twice = true,
			vis[x]++;
		else
			return 0;
	}
	int res = 0;
	for (string nxt : graph[x])
		res += dfs(nxt);
	if (islower(x[0]))
		vis[x]--;
	if (vis[x])
		twice = false;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2;
	while (getline(cin, s1, '-') && s1 != "" && s1 != "\n") {
		getline(cin, s2, '\n');
		graph[s1].push_back(s2);
		graph[s2].push_back(s1);
	}
	printf("%d\n", dfs("start"));
}
