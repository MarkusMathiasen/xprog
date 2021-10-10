#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
map<string, int> m;
set<int> nodes;
vector<string> res;

int main() {
	for (int i = 0; i < (int)v.size(); i++)
		m[v[i]] = i;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		nodes.insert(m[s]);
	}
	for (int i = 0; i < (int)v.size(); i++) {
		if (!(nodes.count((i+1)%12) || nodes.count((i+3)%12) ||
			nodes.count((i+6)%12) || nodes.count((i+8)%12) ||
			nodes.count((i+10)%12)))
			res.push_back(v[i]);
	}
	if (!res.size())
		printf("none\n");
	else {
		for (string s : res)
			cout << s << " ";
		cout << endl;
	}
}
