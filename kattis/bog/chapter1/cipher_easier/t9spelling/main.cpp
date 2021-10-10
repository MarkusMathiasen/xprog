#include <bits/stdc++.h>
using namespace std;

map<char, string> m = {
	{'a', "2"},
	{'b', "22"},
	{'c', "222"},
	{'d', "3"},
	{'e', "33"},
	{'f', "333"},
	{'g', "4"},
	{'h', "44"},
	{'i', "444"},
	{'j', "5"},
	{'k', "55"},
	{'l', "555"},
	{'m', "6"},
	{'n', "66"},
	{'o', "666"},
	{'p', "7"},
	{'q', "77"},
	{'r', "777"},
	{'s', "7777"},
	{'t', "8"},
	{'u', "88"},
	{'v', "888"},
	{'w', "9"},
	{'x', "99"},
	{'y', "999"},
	{'z', "9999"},
	{' ', "0"}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; getline(cin, s);
	int N = stoi(s);
	for (int t = 1; t <= N; t++) {
		getline(cin, s);
		string prev = "x";
		printf("Case #%d: ", t);
		for (char c : s) {
			if (prev[0] == m[c][0])
				printf(" ");
			printf("%s", m[c].c_str());
			prev = m[c];
		}
		printf("\n");
	}
}
