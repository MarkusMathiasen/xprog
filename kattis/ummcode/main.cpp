#include <bits/stdc++.h>
using namespace std;

string parse(string& s) {
	string res = "";
	for (char& c : s) {
		if (!isalpha(c) && !isdigit(c))
			continue;
		if (c != 'u' && c != 'm')
			return "";
		res.push_back(c);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string code = "", s;
	while (cin >> s)
		code += parse(s);
	int pos = 0;
	string result = "";
	while (pos < (int)code.size()) {
		char c = 0;
		for (int i = 0; i < 7; i++, pos++)
			if (code[pos] == 'u')
				c += 1<<(6-i);
		result.push_back(c);
	}
	cout << result << endl;
}
