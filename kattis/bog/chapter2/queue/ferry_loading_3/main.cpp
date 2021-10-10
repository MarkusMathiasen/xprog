#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int high = 2e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c; cin >> c;
	while (c--) {
		int n, t, m; cin >> n >> t >> m;
		queue<ii> left, right;
		for (int i = 0; i < m; i++) {
			int tim; string side; cin >> tim >> side;
			if (side == "left")
				left.push(ii(tim, i));
			else if (side == "right")
				right.push(ii(tim, i));
			else
				throw side;
		}
		left.push(ii(high, -1));
		right.push(ii(high, -1));
		bool isLeft = true;
		int cur = 0;
		vector<int> res(m, -1);
		while (left.front().first != high || right.front().first != high) {
			cur = max(min(left.front().first, right.front().first), cur);
			if ((isLeft && left.front().first > cur) ||
				(!isLeft && right.front().first > cur)) {
				isLeft = !isLeft;
				cur += t;
				continue;
			}
			if (isLeft) {
				int cnt = 0;
				while (left.front().first <= cur && cnt++ < n) {
					res[left.front().second] = cur+t;
					left.pop();
				}
			}
			else {
				int cnt = 0;
				while (right.front().first <= cur && cnt++ < n) {
					res[right.front().second] = cur+t;
					right.pop();
				}
			}
			isLeft = !isLeft;
			cur += t;
		}
		for (int x : res)
			printf("%d\n", x);
		printf("\n");
	}
}
