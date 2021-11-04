#include <bits/stdc++.h>
using namespace std;
#define ss pair<string, string>

unordered_map

bool rhymes(string& a, string& b) {
	int l = min(a.size(), b.size());
	l = min(3, l);
	return a.substr(a.size()-l) == b.substr(b.size()-l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	set<string> words;
	vector<ss> eq, neq;
	while (n--) {
		string w1, cmd, w2; cin >> w1 >> cmd >> w2;
		words.insert(w1); words.insert(w2);
		if (cmd == "is")
			eq.push_back(ss(w1, w2));
		else if (cmd == "not")
			neq.push_back(ss(w1, w2));
		else throw cmd;
	}
	sort(words.begin(), words.end(), [](const string& a, const string& b) {
		if (a.size() != b.size())
			return a.size() < b.size();
		return a < b;
	});
	for (string& x : words) {
		
	}
}
