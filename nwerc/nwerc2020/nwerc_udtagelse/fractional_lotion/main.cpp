#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int main() {
	while (cin >> s) {
		n = stoi(s.substr(2, s.size()-1));
		int res = 0;
		for (int b = n+1; b <= n*2; b++)
			if ((b*n)%(b-n) == 0)
				res++;
		cout << res << endl;
	}
}
