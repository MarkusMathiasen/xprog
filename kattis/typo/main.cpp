#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define L 1000000
#define P1 131
#define P2 137
typedef long long ll;
typedef pair<ll, ll> ii;

vector<vector<ll>> h1, h2;
ll p1[L+1], p2[L+1];
int n;

ii s_hash(int w, int from, int to) {
	ll hash1 = ((h1[w][to] - h1[w][from]*p1[to-from] % M) + M) % M;
	ll hash2 = ((h2[w][to] - h2[w][from]*p2[to-from] % M) + M) % M;
	return ii(hash1, hash2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool no_typos = true;
	cin >> n;
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= L; i++)
		p1[i] = p1[i-1]*P1 % M,
		p2[i] = p2[i-1]*P2 % M;
	h1.assign(n, vector<ll>());
	h2.assign(n, vector<ll>());
	set<ii> dict;
	vector<string> words(n, "");
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		h1[i].assign(words[i].size()+1, 0);
		h2[i].assign(words[i].size()+1, 0);
		for (int j = 0; j < (int)words[i].size(); j++)
			h1[i][j+1] = (h1[i][j]*P1 + words[i][j]) % M,
			h2[i][j+1] = (h2[i][j]*P2 + words[i][j]) % M;
		dict.insert(ii(h1[i][words[i].size()], h2[i][words[i].size()]));
	}
	for (int w = 0; w < n; w++) {
		for (int x = 0; x < (int)words[w].size(); x++) {
			auto [h1a, h2a] = s_hash(w, 0, x);
			auto [h1b, h2b] = s_hash(w, x+1, words[w].size());
			ll h1c = (h1a*p1[words[w].size()-x-1] + h1b)%M;
			ll h2c = (h2a*p2[words[w].size()-x-1] + h2b)%M;
			if (dict.count(ii(h1c, h2c))) {
				no_typos = false;
				printf("%s\n", words[w].c_str());
				break;
			}
		}
	}
	if (no_typos)
		printf("NO TYPOS\n");
}
