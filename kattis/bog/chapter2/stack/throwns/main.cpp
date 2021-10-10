#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	stack<int> pos;
	pos.push(0);
	for (int i = 0; i < k; i++) {
		string cmd; cin >> cmd;
		if (cmd == "undo") {
			int x; cin >> x;
			while (x--)
				pos.pop();
			continue;
		}
		int x = stoi(cmd)%n;
		x += pos.top();
		if (x < 0)
			x += n;
		else if (x >= n)
			x -= n;
		pos.push(x);
	}
	printf("%d\n", pos.top());
}
