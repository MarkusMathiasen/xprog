#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line, word; getline(cin, line);
	map<string, int> m;
	vector<string> ats;
	stringstream ss(line);
	int cnt = 0;
	while (ss >> word) {
		m[word] = cnt++;
		ats.push_back(word);
	}
	int n; cin >> n;
	vector<vector<string>> songs(n, vector<string>(cnt, ""));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < cnt; j++)
			cin >> songs[i][j];
	int cmds; cin >> cmds;
	for (int i = 0; i < cmds; i++) {
		string cmd; cin >> cmd;
		int x = m[cmd];
		stable_sort(songs.begin(), songs.end(), [x](vector<string> const& a, vector<string> const& b) {
			return a[x] < b[x];
		});
		for (int i = 0; i < (int)ats.size(); i++)
			cout << ats[i] << " ";
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < cnt; j++)
				cout << songs[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
}
