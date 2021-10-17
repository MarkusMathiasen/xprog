#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n; cin >> m >> n;
	unordered_map<string, int> points;
	while (m--) {
		string w; int x; cin >> w >> x;
		points[w] = x;
	}
	while (n--) {
		string s; getline(cin, s, '.');
		stringstream ss(s);
		string word;
		int res = 0;
		while (ss >> word)
			res += points[word];
		printf("%d\n", res);
	}
}
