#include <bits/stdc++.h>
using namespace std;
#define ss pair<string, string> 

unordered_map<string, string> p;

bool rhymes(const string& a, const string& b) {
	if (b.size() < a.size())
		return b == a.substr(0, b.size());
	return a == b.substr(0, a.size());
}

const string& find(const string& x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	if (n == 0) {
		printf("yes\n");
		return 0;
	}
	set<string> words;
	vector<ss> eq, neq;
	while (n--) {
		string a, cmd, b; cin >> a >> cmd >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		a = a.substr(0, 3);
		b = b.substr(0, 3);
		words.insert(a);
		words.insert(b);
		if (cmd == "is")
			eq.push_back(ss(a, b));
		else if (cmd == "not")
			neq.push_back(ss(a, b));
		else throw cmd;
	}
	string prev = *words.begin();
	p[prev] = prev;
	for (const string& x : words) {
		if (rhymes(prev, x))
			p[x] = prev;
		else
			p[x] = x;
		prev = p[x];
	}
	for (auto& [a,b] : eq) {
		string A = find(a);
		string B = find(b);
		if (A != B)
			p[A] = B;
	}
	bool res = true;
	for (const auto& [a,b] : neq)
		res &= find(a) != find(b);
	printf(res ? "yes\n" : "wait what?\n");
}
