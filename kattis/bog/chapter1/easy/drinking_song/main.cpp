#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	n++;
	while (--n) {
		cout << n << "bottles of milk on the wall, " << n 
		<< "bottles of milk.\n";
		if (n > 1)
			cout << "Take one down, pass it around, " << n-1
			<< (n-1 == 1 ? "bottle" else "bottles")
	}
}
