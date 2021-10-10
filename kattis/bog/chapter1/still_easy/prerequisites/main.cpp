#include <bits/stdc++.h>
using namespace std;

int k, m;
vector<int> req;
vector<string> courses;
vector<set<string>> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> k >> m) {
		courses.assign(k, "");
		req.assign(m, 0);
		c.assign(m, set<string>());
		for (int i = 0; i < k; i++)
			cin >> courses[i];
		for (int i = 0; i < m; i++) {
			int x; cin >> x >> req[i];
			while (x--) {
				string y; cin >> y;
				c[i].insert(y);
			}
		}
		vector<int> taken(m, 0);
		for (string course : courses)
			for (int i = 0; i < m; i++)
				if (c[i].count(course))
					taken[i]++;
		bool res = true;
		for (int i = 0; i < m; i++)
			if (taken[i] < req[i])
				res = false;
		printf(res ? "yes\n" : "no\n");
	}
}
