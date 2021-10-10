#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	stack<string> events;
	unordered_map<string, int> m;
	while (n--) {
		string cmd; cin >> cmd;
		if (cmd == "E") {
			string s; cin >> s;
			m[s] = events.size();
			events.push(s);
		} else if (cmd == "D") {
			int x; cin >> x;
			for (int i = 0; i < x; i++) {
				m.erase(events.top());
				events.pop();
			}
		}
		else { assert(cmd == "S");
			vector<string> should, shouldNot;
			int x; cin >> x;
			for (int i = 0; i < x; i++) {
				string s; cin >> s;
				if (s[0] == '!')
					shouldNot.push_back(s.substr(1, s.size()-1));
				else
					should.push_back(s);
			}
			bool yesShould = true;
			bool noShouldNot = true;
			for (string s : should)
				yesShould &= m.count(s);
			for (string s : shouldNot)
				noShouldNot &= !m.count(s);
			if (yesShould && noShouldNot) {
				printf("Yes\n");
				continue;
			}
			if (!yesShould) {
				printf("Plot Error\n");
				continue;
			}
			int maxYes = -1;
			for (string s : should)
				maxYes = max(maxYes, m[s]);
			int minNo = events.size();
			for (string s : shouldNot)
				if (m.count(s))
					minNo = min(minNo, m[s]);
			if (minNo > maxYes)
				printf("%d Just A Dream\n", (int)events.size()-minNo);
			else
				printf("Plot Error\n");
		}
	}
}
