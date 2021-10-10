#include <bits/stdc++.h>

using namespace std;

int x, y, n;

int main() {
	cin >> x >> y >> n;
	for (int i = 1; i <= n; i++) {
		string res = "";
		if (i % x == 0)
			res += "Fizz";
		if (i % y == 0)
			res += "Buzz";
		if (res == "")
			cout << i << endl;
		else
			cout << res << endl;
	}
}
