#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; getline(cin, s);
	int t = stoi(s);
	while (t--) {
		getline(cin, s);
		stack<char> backpack;
		bool failure = false;
		for (char c : s) {
			if (c == '.')
				continue;
			else if (c == '$' || c == '|' || c == '*')
				backpack.push(c);
			else if (c == 't') {
				if (backpack.size() && backpack.top() == '|')
					backpack.pop();
				else
					failure = true;
			}
			else if (c == 'j') {
				if (backpack.size() && backpack.top() == '*')
					backpack.pop();
				else
					failure = true;
			}
			else if (c == 'b') {
				if (backpack.size() && backpack.top() == '$')
					backpack.pop();
				else
					failure = true;
			}
			else
				throw c;
		}
		printf(failure || backpack.size() ? "NO\n" : "YES\n");
	}
}
