#include <bits/stdc++.h>
using namespace std;

vector<string> before, after;
int n, letterCount = 0;
vector<string> underTwenty = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string res;

string& letters(int x) {
	res = "";
	if (x >= 100)
		res += underTwenty[x/100]+"hundred";
	x %= 100;
	if (x >= 20)
		res += tens[x/10] + underTwenty[x%10];
	else
		res += underTwenty[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	string s;
	while (cin >> s && s != "$")
		before.push_back(s), letterCount += s.size();
	while (cin >> s)
		after.push_back(s), letterCount += s.size();
	for (int i = 1; true; i++) {
		s = letters(i);
		if ((int)s.size() + letterCount == i) {
			for (string& x : before)
				printf("%s ", x.c_str());
			printf("%s", s.c_str());
			for (string& x : after)
				printf(" %s", x.c_str());
			printf("\n");
			break;
		}
	}
}
