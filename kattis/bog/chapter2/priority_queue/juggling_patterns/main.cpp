#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s) {
		vector<int> pat;
		for (char c : s)
			pat.push_back(c-'0');
		int sum = 0;
		for (int x : pat)
			sum += x;
		if (sum%pat.size() != 0) {
			printf("%s: invalid # of balls\n", s.c_str());
			continue;
		}
		int ballCount = sum/pat.size();
		int balls = ballCount;
		priority_queue<int, vector<int>, greater<int>> Q;
		bool possible = true;
		for (int tim = 0; tim < 10000; tim++) {
			int height = pat[tim%pat.size()];
			if (height <= 0)
				continue;
			if ((Q.empty() || Q.top() > tim) && balls)
				Q.push(tim), balls--;
			possible &= !Q.empty();
			if (Q.top() == tim) {
				balls++;
				Q.pop();
			}
			possible &= balls && (Q.empty() || Q.top() > tim);
			Q.push(tim+height);
			balls--;
		}
		if (possible)
			printf("%s: valid with %d balls\n", s.c_str(), ballCount);
		else
			printf("%s: invalid pattern\n", s.c_str());
	}
}
