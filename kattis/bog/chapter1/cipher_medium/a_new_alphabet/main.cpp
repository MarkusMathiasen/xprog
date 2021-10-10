#include <bits/stdc++.h>
using namespace std;

map<char, string> m = {
	{'a', "@"},
	{'b', "8"},
	{'c', "("},
	{'d', "|)"},
	{'e', "3"},
	{'f', "#"},
	{'g', "6"},
	{'h', "[-]"},
	{'i', "|"},
	{'j', "_|"},
	{'k', "|<"},
	{'l', "1"},
	{'m', "[]\\/[]"},
	{'n', "[]\\[]"},
	{'o', "0"},
	{'p', "|D"},
	{'q', "(,)"},
	{'r', "|Z"},
	{'s', "$"},
	{'t', "']['"},
	{'u', "|_|"},
	{'v', "\\/"},
	{'w', "\\/\\/"},
	{'x', "}{"},
	{'y', "`/"},
	{'z', "2"}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; getline(cin, s);
	for (char c : s)
		if (isalpha(c))
			printf("%s", m[tolower(c)].c_str());
		else
			printf("%c", c);
	printf("\n");
}
