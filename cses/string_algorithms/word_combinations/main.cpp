#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;

int trie[1000001][26];
bool star[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; int n; cin >> s >> n;
	int cnt = 1;
	while (n--) {
		string w; cin >> w;
		int pos = 0;
		for (char c : w) {
			if (!trie[pos][c-'a'])
				trie[pos][c-'a'] = cnt++;
			pos = trie[pos][c-'a'];
		}
		star[pos] = true;
	}
	vector<ll> dp(s.size()+1, 0);
	dp[0] = 1;
	for (int i = 0; i < (int)s.size(); i++) {
		int tp = 0;
		for (int c = i; c <= (int)s.size(); c++) {
			if (star[tp])
				dp[c] = (dp[c] + dp[i]) % M;
			if (c == (int)s.size())
				break;
			if (!trie[tp][s[c]-'a'])
				break;
			tp = trie[tp][s[c]-'a'];
		}
	}
	printf("%lld\n", dp[s.size()]);
}
