#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 100000*32+1;

int trie[MAXN][26];
int node_val[MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	int node_cnt = 1;
	while (N--) {
		int node = 0;
		string word; cin >> word;
		for (char c : word) {
			int& nxt = trie[node][c-'a'];
			if (nxt == 0)
				nxt = node_cnt++;
			node = nxt;
			node_val[node]++;
		}
		printf("%d\n", node_val[node]-1);
	}
}
