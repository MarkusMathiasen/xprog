#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c; cin >> c;
	while (c--) {
		int l, m; cin >> l >> m;
		l *= 100;
		queue<int> left, right;
		while (m--) {
			int len; string side; cin >> len >> side;
			if (side == "left")
				left.push(len);
			else if (side == "right")
				right.push(len);
			else
				throw side;
		}
		bool isLeft = true;
		int res = 0;
		while (left.size() || right.size()) {
			int cur = 0;
			if (isLeft) {
				while (left.size() && left.front()+cur <= l)
					cur += left.front(), left.pop();
			}
			else {
				while (right.size() && right.front()+cur <= l)
					cur += right.front(), right.pop();
			}
			isLeft = !isLeft;
			res++;
		}
		printf("%d\n", res);
	}
}
