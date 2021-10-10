#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	bool prev = false;
	int res = false;
	for (char c : s) {
		if (prev && c == 's')
			res = true;
		prev = c == 's';
	}
	printf(res ? "hiss\n" : "no hiss\n");
}
