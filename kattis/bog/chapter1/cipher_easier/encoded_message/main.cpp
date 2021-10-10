#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int n = round(sqrt(s.size()));
		for (int col = n-1; col >= 0; col--)
			for (int row = 0; row < n; row++)
				printf("%c", s[row*n+col]);
		printf("\n");
	}
}
