#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, res = 0; cin >> n;
	while (n--) {
		int x; cin >> x;
		res += max(0, -x);
	}
	cout << res << endl;
}
