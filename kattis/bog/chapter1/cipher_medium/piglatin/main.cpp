#include <bits/stdc++.h>
using namespace std;

string vowels = "aeiouy";
bool isvowel(char c) {return vowels.find(c) != string::npos;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		string word;
		while (ss >> word) {
			int x;
			for (x = 0; x < (int)word.size(); x++) {
				if (isvowel(word[x]))
					break;
				word.push_back(word[x]);
			}
			cout << word.substr(x, word.size()-x) + (x == 0 ? "yay" : "ay") + " ";
		}
		cout << "\n";
	}
}
