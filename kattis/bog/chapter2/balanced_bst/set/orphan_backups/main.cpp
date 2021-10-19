#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> b1;
	set<string> b2;
	map<string, set<string>> fullNames;
	string s;
	while (getline(cin, s) && s != "")
		b1.insert(s);
	while (getline(cin, s)) {
		stringstream ss(s);
		vector<string> parts;
		while (getline(ss, s, '_'))
			parts.push_back(s);
		s = parts[0];
		for (int i = 1; i < (int)parts.size()-2; i++)
			s += "_" + parts[i];
		b2.insert(s);
		fullNames[s].insert(s + "_" + parts[parts.size()-2] + "_" + parts.back());
	}
	vector<string> res;
	for (string x : b1)
		if (!b2.count(x))
			res.push_back("I " + x);
	for (string x : b2)
		if (!b1.count(x))
			for (string x2 : fullNames[x])
				res.push_back("F " + x2);
	sort(res.begin(), res.end());
	for (string x : res)
		cout << x << "\n";
	if (!res.size())
		printf("No mismatches.\n");
}
