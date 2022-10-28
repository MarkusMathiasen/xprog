#include <bits/stdc++.h>
using namespace std;
#define M 1000000007ll
#define P1 131ll
#define P2 127ll
typedef long long ll;

vector<ll> h1, p1, h2, p2;
unordered_map<ll, int> htoi;
vector<int> lengths;
set<int> length_set;
vector<string> dict, cdict;
vector<int> dp, dps;

int n;
string s;

ll s_hash(int from, int to) {
	ll hash1 = ((h1[to] - h1[from]*p1[to-from])%M+M)%M;
	ll hash2 = ((h2[to] - h2[from]*p2[to-from])%M+M)%M;
	return (hash1 << 32) | hash2;
}

void init_hp() {
	h1.assign(s.size()+1, 0);
	h2.assign(s.size()+1, 0);
	p1.assign(s.size()+1, 1);
	p2.assign(s.size()+1, 1);
	for (int i = 1; i <= (int)s.size(); i++)
		h1[i] = ((h1[i-1]*P1 + s[i-1])%M+M)%M,
		h2[i] = ((h2[i-1]*P2 + s[i-1])%M+M)%M,
		p1[i] = p1[i-1]*P1 % M,
		p2[i] = p2[i-1]*P2 % M;
}

ll s_hash(string& s) {
	ll hash1 = 0;
	ll hash2 = 0;
	for (int i = 0; i < (int)s.size(); i++)
		hash1 = (hash1*P1 + s[i]) % M,
		hash2 = (hash2*P2 + s[i]) % M;
	return (hash1 << 32) | hash2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dict.assign(n, "");
	cdict.assign(n, "");
	for (int i = 0; i < n; i++) {
		cin >> dict[i];
		for (char c : dict[i])
			if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
				cdict[i].push_back(c);
		ll h = s_hash(cdict[i]);
		if (!htoi.count(h) || dict[htoi[h]].size() < dict[i].size())
			htoi[s_hash(cdict[i])] = i;
		if (!length_set.count(cdict[i].size()))
			lengths.push_back(cdict[i].size());
		length_set.insert(cdict[i].size());
	}
	sort(lengths.begin(), lengths.end());
	cin >> s;
	init_hp();
	dp.assign(s.size()+1, 0);
	dp[0] = 1;
	dps.assign(s.size()+1, 0);
	for (int from = 0; from < (int)s.size(); from++) {
		if (!dp[from])
			continue;
		for (int length : lengths) {
			if (from + length > (int)s.size())
				break;
			ll h = s_hash(from, from+length);
			if (htoi.count(h)) {
				int i = htoi[h];
				if (dp[from+length] < dp[from] + (int)dict[i].size()) {
					dp[from+length] = dp[from] + dict[i].size();
					dps[from+length] = i;
				}
			}
		}
	}
	int pos = s.size();
	stack<int> res;
	while (pos) {
		res.push(dps[pos]);
		pos -= cdict[dps[pos]].size();
	}
	while (!res.empty()) {
		printf("%s ", dict[res.top()].c_str());
		res.pop();
	}
	printf("\n");
}
