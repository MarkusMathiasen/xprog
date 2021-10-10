#include <bits/stdc++.h>

using namespace std;

int n;
int low = 1000000001;
int res = -1;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x < low) {
			low = x;
			res = i;
		}
	}
	cout << res << endl;
}
