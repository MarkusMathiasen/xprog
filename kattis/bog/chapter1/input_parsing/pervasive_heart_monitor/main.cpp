#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while (getline(cin, line), line != "") {
		stringstream ss(line);
		string word, name = "";
		double sum = 0;
		int am = 0;
		while (ss >> word) {
			if (isalpha(word[0]))
				name += " " + word;
			else
				sum += stod(word), am++;
		}
		cout << sum/am << name << endl;
	}
}
