#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	string res((int)s.size(), 'z');
	for (int a = 1; a < (int)s.size()-1; a++)
		for (int b = a+1; b < (int)s.size(); b++) {
			string x, y, z;
			x = s.substr(0, a);
			y = s.substr(a, b-a);
			z = s.substr(b, (int)s.size()-b);
			reverse(x.begin(), x.end());
			reverse(y.begin(), y.end());
			reverse(z.begin(), z.end());
			res = min(res, x+y+z);
		}
	cout << res << endl;
}
