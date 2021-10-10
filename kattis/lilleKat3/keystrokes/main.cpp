#include <bits/stdc++.h>

using namespace std;

string ops;
list<char> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> ops;
	auto it = p.begin();
	for (char c : ops) {
		if (c == 'L') {
			if (it != p.begin())
				it--;
		}
		else if (c == 'R') {
			if (it != p.end())
				it++;
		}
		else if (c == 'B') {
			if (it != p.begin()) {
				it--;
				it = p.erase(it);
			}
		}
		else {
			p.insert(it, c);
		}
	}
	for (char c : p)
		printf("%c", c);
	printf("\n");
}
