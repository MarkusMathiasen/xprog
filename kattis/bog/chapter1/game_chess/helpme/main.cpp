#include <bits/stdc++.h>
using namespace std;

string s;
stringstream ss;
vector<string> white, black;
map<char, int> m = {
	{'K', 0},
	{'Q', 1},
	{'R', 2},
	{'B', 3},
	{'N', 4}
};

bool compWhite(string s1, string s2) {
	if (s1.size() != s2.size())
		return s2.size() < s1.size();
	if (s1[0] == s2[0] || islower(s1[0])) {
		if (s1.back() == s2.back()) {
			int pos = s1.size()-2;
			return s1[pos] < s2[pos];
		}
		return s1.back() < s2.back();
	}
	return m[s1[0]] < m[s2[0]];
}
bool compBlack(string s1, string s2) {
	if (s1.size() != s2.size())
		return s2.size() < s1.size();
	if (s1[0] == s2[0] || islower(s1[0])) {
		if (s1.back() == s2.back()) {
			int pos = s1.size()-2;
			return s1[pos] < s2[pos];
		}
		return s1.back() > s2.back();
	}
	return m[s1[0]] < m[s2[0]];
}

int main() {
	for (int row = 8; row > 0; row--) {
		getline(cin, s);
		getline(cin, s);
		ss.str(s);
		getline(ss, s, '|');
		for (char c = 'a'; c != 'i'; c++) {
			getline(ss, s, '|');
			char p = s[1];
			if (p == '.' || p == ':')
				continue;
			string coord = c + to_string(row);
			string val;
			if (tolower(p) == 'p')
				val = coord;
			else {
				val.push_back(toupper(p));
				val += coord;
			}
			if (islower(p))
				black.push_back(val);
			else
				white.push_back(val);
		}
	}
	
	sort(white.begin(), white.end(), compWhite);
	sort(black.begin(), black.end(), compBlack);
	
	printf("White: ");
	for (int i = 0; i < (int)white.size(); i++) {
		if (i != 0)
			printf(",");
		cout << white[i];
	}printf("\n");
	printf("Black: ");
	for (int i = 0; i < (int)black.size(); i++) {
		if (i != 0)
			printf(",");
		cout << black[i];
	}printf("\n");
}
