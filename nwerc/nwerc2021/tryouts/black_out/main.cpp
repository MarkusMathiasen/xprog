#include <bits/stdc++.h>
using namespace std;

void print(int a, int b, int c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

int main() {
	int T; cin >> T;
	while (T--) {
		print(3, 1, 3, 6);
		string s;
		while (cin >> s, s != "GAME") {
			int a, b, c, d; cin >> a >> b >> c >> d;
			print(6-c, 7-d, 6-a, 7-b);
		}
	}
}
