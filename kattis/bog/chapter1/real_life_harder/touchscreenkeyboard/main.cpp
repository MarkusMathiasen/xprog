#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>
#define ii pair<int, int>

int t;
vector<string> board = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

ii coord(char c) {
	for (int i = 0; i < 3; i++)
		if (board[i].rfind(c) != string::npos)
			return ii(i, board[i].rfind(c));
	throw 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		vector<is> res;
		string word; int n; cin >> word >> n;
		while (n--) {
			string s; cin >> s;
			int dist = 0;
			for (int i = 0; i < (int)word.size(); i++) {
				ii k1 = coord(s[i]);
				ii k2 = coord(word[i]);
				dist += abs(k1.first - k2.first) + abs(k1.second - k2.second);
			}
			res.push_back(is(dist, s));
		}
		sort(res.begin(), res.end());
		for (is x : res)
			printf("%s %d\n", x.second.c_str(), x.first);
	}
}
