#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (getline(cin, s) && s != "") {
		int l = 0, r = 0;
		for (char c : s)
			for (int i = 0; i < 7; i++)
				c & (1 << i) ? l++ : r++;
		printf(l%2 || r%2 ? "trapped\n" : "free\n");
	}
}
