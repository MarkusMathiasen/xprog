#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	string s; getline(cin, s);
	while (t--) {
		vector<bool> A(26, false);
		getline(cin, s);
		for (char c : s)
			if (isalpha(c))
				A[tolower(c)-'a'] = true;
		string missing = "";
		for (int i = 0; i < (int)A.size(); i++)
			if (!A[i])
				missing.push_back('a'+i);
		if (missing.size())
			printf("missing %s\n", missing.c_str());
		else
			printf("pangram\n");
	}
}
