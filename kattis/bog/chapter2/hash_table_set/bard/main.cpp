#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, e; cin >> n >> e;
	int songCnt = 1;
	vector<set<int>> v(n+1, set<int>());
	string s; getline(cin, s);
	for (int i = 0; i < e; i++) {
		set<int> present;
		getline(cin, s);
		stringstream ss(s);
		int x; ss >> x;
		while (ss >> x)
			present.insert(x);
		if (present.count(1)) {
			for (int x : present)
				v[x].insert(songCnt);
			songCnt++;
		}
		else {
			for (int x : present)
				for (int song : v[x])
					for (int y : present)
						v[y].insert(song);
		}
	}	
	for (int i = 1; i <= n; i++)
		if (v[i].size() == v[1].size())
			printf("%d\n", i);
}
