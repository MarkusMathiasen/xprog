#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s) {
		if (s == "END")
			break;
		int res = 0;
		while (s.size() > 1) {
			res++;
			s = to_string(s.size());
		}
		int x = stoi(s);
		if (x == 1)
			printf("%d\n", res+1);
		else
			printf("%d\n", res+2);
	}

}
