#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, char> cc;

vector<vector<vector<vector<ll>>>> dp(26, vector<vector<vector<ll>>>(26, vector<vector<ll>>(41, vector<ll>(26, -1))));
map<cc, char> m;
map<char, ll> freq;

vector<ll> step(char a, char b, ll steps) {
	if (steps == 0)
		return vector<ll>(26, 0);
	if (dp[a-'A'][b-'A'][steps][0] != -1)
		return dp[a-'A'][b-'A'][steps];
	dp[a-'A'][b-'A'][steps] = vector<ll>(26, 0);
	for (auto& [p,c] : m)
		if (p.first == a && p.second == b) {
			vector<ll> A = step(a, c, steps-1);
			vector<ll> B = step(c, b, steps-1);
			for (ll i = 0; i < 26; i++)
				dp[a-'A'][b-'A'][steps][i] += A[i] + B[i];
			dp[a-'A'][b-'A'][steps][c-'A']++;
			return dp[a-'A'][b-'A'][steps];
		}
	return dp[a-'A'][b-'A'][steps];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	list<char> l;
	for (char c : s)
		l.push_back(c);
	string a, b;
	while (cin >> a >> b >> b)
		m[cc(a[0], a[1])] = b[0];
	
	for (auto it = l.begin(); it != l.end();) {
		char c1 = *it;
		it++;
		if (it == l.end())
			break;
		char c2 = *it;
		vector<ll> A = step(c1, c2, 40);
		for (ll i = 0; i < 26; i++)
			freq['A'+i] += A[i];
	}
	for (char c : l)
		freq[c]++;
	ll high = 0, low = 1e18;
	for (auto& [c,x] : freq)
		high = max(high, x),
			 low = x > 0 ? min(low, x) : low;
	printf("%lld\n", high-low);
}
