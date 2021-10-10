#include <bits/stdc++.h>
using namespace std;

string pre, curr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> pre;
	cout << pre;
	while (cin >> curr) {
		if (pre + "\'s" == curr) {
			cout << '*';
			continue;
		}
		int x = min(pre.size(), curr.size());
		for (int i = 0; i < x; i++)
			if (pre[i] != curr[i]) {
				x = i;
				break;
			}
		cout << x;
		cout << curr.substr(x, curr.size()-x);
		pre = curr;
	}
	cout << endl;
}
