#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while (getline(cin, line), line != "") {
		stringstream ss(line);
		string s; ss >> s;
		set<string> domain;
		map<string, int> codomain;
		while (ss >> s)
			domain.insert(s);
		getline(cin, line);
		ss.str(line);
		ss.clear();
		ss >> s;
		while (ss >> s)
			codomain[s] = 0;
		int n; cin >> n;
		bool isFunction = true;
		while (n--) {
			string a, x, b; cin >> a >> x >> b;
			if (!domain.count(a))
				isFunction = false;
			codomain[b]++;
			domain.erase(a);
		}
		getline(cin, line);
		bool injective = true, surjective = true;
		if (!isFunction)
			printf("not a function\n");
		else {
			for (auto p : codomain) {
				injective &= p.second <= 1;
				surjective &= p.second >= 1;
			}
			if (injective && surjective)
				printf("bijective\n");
			else if (injective)
				printf("injective\n");
			else if (surjective)
				printf("surjective\n");
			else
				printf("neither injective nor surjective\n");
		}

	}
}
