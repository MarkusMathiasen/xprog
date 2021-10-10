#include <bits/stdc++.h>
using namespace std;

int main() {
	bool can = false;
	string s;
	cin >> s;
	for (char c : s) {
		if (can) {
			if (c == 's')
				cout << '*';
			else
				cout << '\'' << c;
		}
		else {
			if (c == '\'')
				can = true;
			else
				cout << c;
		}
		can = c == '\'';
	}
}
