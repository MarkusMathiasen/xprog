#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int res = 0;
	while (n--) {
		int x; cin >> x;
		res += x < 0;
	}
	cout << res << endl;
}
