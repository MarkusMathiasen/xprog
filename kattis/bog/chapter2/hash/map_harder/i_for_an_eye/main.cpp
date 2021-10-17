#include <bits/stdc++.h>
using namespace std;

void makeLower(string& s) {
	for (char& c : s)
		c = tolower(c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	string line; getline(cin, line);
	while (n--) {
		getline(cin, line);
		string res = "";
		for (int i = 0; i < (int)line.size(); i++) {
			string x4 = (line.substr(i, 4));
			string x3 = (line.substr(i, 3));
			string x2 = (line.substr(i, 2));
			makeLower(x2);
			makeLower(x3);
			makeLower(x4);
			if (x2 == "at")
				res += "@", i++;
			else if (x3 == "and")
				res += "&", i+=2;
			else if (x3 == "one" || x3 == "won")
				res += "1", i+=2;
			else if (x3 == "two" || x3 == "too")
				res += "2", i+=2;
			else if (x2 == "to")
				res += "2", i++;
			else if (x4 == "four")
				res += "4", i+=3;
			else if (x3 == "for")
				res += "4", i+=2;
			else if (x3 == "bea" || x3 == "bee")
				res += (isupper(line[i]) ? "B" : "b"), i+=2;
			else if (x2 == "be")
				res += (isupper(line[i]) ? "B" : "b"), i++;
			else if (x3 == "sea" || x3 == "see")
				res += (isupper(line[i]) ? "C" : "c"), i+=2;
			else if (x3 == "eye")
				res += (isupper(line[i]) ? "I" : "i"), i+=2;
			else if (x3 == "owe")
				res += (isupper(line[i]) ? "O" : "o"), i+=2;
			else if (x2 == "oh")
				res += (isupper(line[i]) ? "O" : "o"), i+=1;
			else if (x3 == "are")
				res += (isupper(line[i]) ? "R" : "r"), i+=2;
			else if (x3 == "you")
				res += (isupper(line[i]) ? "U" : "u"), i+=2;
			else if (x3 == "why")
				res += (isupper(line[i]) ? "Y" : "y"), i+=2;
			else
				res.push_back(line[i]);
		}
		printf("%s\n", res.c_str());
	}
}
