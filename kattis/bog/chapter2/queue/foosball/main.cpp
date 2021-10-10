#include <bits/stdc++.h>
using namespace std;
#define ii pair<string, string>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	queue<string> q;
	string wo, bo, wd, bd; cin >> wo >> bo >> wd >> bd;
	for (int i = 0; i < n-4; i++) {
		string s; cin >> s;
		q.push(s);
	}
	string wins; cin >> wins;
	int best = 0;
	vector<ii> results;
	int streak = 0;
	char streaking = 'W';
	map<string, int> arr;
	int cnt = 1;
	arr[wo] = cnt++;
	arr[bo] = cnt++;
	arr[wd] = cnt++;
	arr[bd] = cnt++;
	for (char c : wins) {
		if (c == 'W') {
			// rotate white
			string tmp = wo;
			wo = wd;
			wd = tmp;
			//swap black
			q.push(bd);
			bd = bo;
			bo = q.front(); arr[bo] = cnt++;
			q.pop();
			// manage streak
			if (streaking == 'W')
				streak++;
			else
				streak = 1, streaking = 'W';
			if (streak > best) {
				best = streak;
				results.clear();
			}
			if (streak == best) {
				if (arr[wo] < arr[wd])
					results.push_back(ii(wo, wd));
				else
					results.push_back(ii(wd, wo));
			}
		} else if (c == 'B') {
			// rotate black
			string tmp = bo;
			bo = bd;
			bd = tmp;
			//swap white
			q.push(wd);
			wd = wo;
			wo = q.front(); arr[wo] = cnt++;
			q.pop();
			// manage streak
			if (streaking == 'B')
				streak++;
			else
				streak = 1, streaking = 'B';
			if (streak > best) {
				best = streak;
				results.clear();
			}
			if (streak == best) {
				if (arr[bo] < arr[bd])
					results.push_back(ii(bo, bd));
				else
					results.push_back(ii(bd, bo));
			}
		}
		else throw c;
	}
	for (auto& [p1,p2] : results)
		printf("%s %s\n", p1.c_str(), p2.c_str());
}
