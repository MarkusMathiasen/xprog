#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	map<char, int> errorCost = {
		{')', 1},
		{']', 2},
		{'}', 3},
		{'>', 4}
	};
	vector<ll> scores;
	while (cin >> s && s != "") {
		ll score = 0;
		stack<char> st;
		bool corrupted = false;
		for (char c : s) {
			if (c == '(')
				st.push(')');
			else if (c == '[')
				st.push(']');
			else if (c == '{')
				st.push('}');
			else if (c == '<')
				st.push('>');
			else {
				assert(!st.empty());
				char d = st.top(); st.pop();
				if (c != d) {
					corrupted = true;
					break;
				}
			}
		}
		if (!corrupted) {
			while (!st.empty())
				score *= 5,
				score += errorCost[st.top()],
				st.pop();
			scores.push_back(score);
		}
	}
	sort(scores.begin(), scores.end());
	printf("%lld\n", scores[scores.size()/2]);
}
