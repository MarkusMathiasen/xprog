#include <bits/stdc++.h>
using namespace std;

vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

int conv(string s) {
	int res = 0;
	for (int i = 9; i > 0; i--) {
		string ten = tens[i];
		if (s.size() >= ten.size() && s.substr(0, ten.size()) == ten) {
			res += i*10;
			s = s.substr(ten.size(), s.size()-ten.size());
			break;
		}
	}
	for (int i = 9; i >= 0; i--) {
		string one = ones[i];
		if (s == one)
			return res+i;
	}
	return 10000;
}

int main() {
	string s; cin >> s;
	int num = conv(s);
	string res = s;
	sort(s.begin(), s.end());
	do {
		if (conv(s) < num)
			num = conv(s), res = s;
	} while (next_permutation(s.begin(), s.end()));
	cout << res << endl;
}
