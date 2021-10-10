#include <bits/stdc++.h>
using namespace std;

int n, k;

set<string> seen, remember, taken;
vector<string> cards;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cards.assign(n, "?");
	for (int i = 0; i < k; i++) {
		int p1, p2; string s1, s2;
		cin >> p1 >> p2 >> s1 >> s2; p1--; p2--;
		if (cards[p1] == "?") {
			if (seen.count(s1))
				remember.insert(s1);
			seen.insert(s1);
			cards[p1] = s1;
		}
		if (cards[p2] == "?") {
			if (seen.count(s2))
				remember.insert(s2);
			seen.insert(s2);
			cards[p2] = s2;
		}
		if (s1 == s2)
			taken.insert(s1);
	}
	int res = (int)remember.size() == n/2-1;
	res += remember.size() - taken.size();
	if (seen.size() == n/2)
		res = n/2 - taken.size();
	cout << res << endl;
}
