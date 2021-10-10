#include <bits/stdc++.h>
using namespace std;

map<char, string> m = {
	{'A', ".-"},
	{'B', "-..."},
	{'C', "-.-."},
	{'D', "-.."},
	{'E', "."},
	{'F', "..-."},
	{'G', "--."},
	{'H', "...."},
	{'I', ".."},
	{'J', ".---"},
	{'K', "-.-"},
	{'L', ".-.."},
	{'M', "--"},
	{'N', "-."},
	{'O', "---"},
	{'P', ".--."},
	{'Q', "--.-"},
	{'R', ".-."},
	{'S', "..."},
	{'T', "-"},
	{'U', "..-"},
	{'V', "...-"},
	{'W', ".--"},
	{'X', "-..-"},
	{'Y', "-.--"},
	{'Z', "--.."},
	{'_', "..--"},
	{',', ".-.-"},
	{'.', "---."},
	{'?', "----"}
};

char rev(string s) {
	for (auto p : m)
		if (p.second == s)
			return p.first;
	throw s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s) {
		string morse = "", nums = "";
		for (char c : s)
			morse += m[c], nums += to_string(m[c].size());
		reverse(nums.begin(), nums.end());
		int pos = 0;
		string res = "";
		for (char c : nums) {
			int n = c - '0';
			res.push_back(rev(morse.substr(pos, n)));
			pos += n;
		}
		cout << res << endl;
	}
}
