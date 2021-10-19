#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>

struct skill {
	string n;
	int s;
	skill(string n, int s) : n(n), s(s) {}
	bool operator < (const skill& a) const {
		if (s != a.s)
			return s < a.s;
		return n > a.n;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	set<string> players;
	vector<priority_queue<skill>> s(3, priority_queue<skill>());
	for (int t = 0; t < n; t++) {
		string name; cin >> name;
		players.insert(name);
		for (int j = 0; j < 3; j++) {
			int x; cin >> x;
			s[j].push(skill(name, x));
		}
	}
	for (int i = 0; i < n/3; i++) {
		set<string> res;
		string name;
		for (int j = 0; j < 3; j++) {
			while (!players.count(s[j].top().n))
				s[j].pop();
			name = s[j].top().n;
			s[j].pop();
			res.insert(name);
			players.erase(name);
		}
		for (string x : res)
			printf("%s ", x.c_str());
		printf("\n");
	}
}
