#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	string line;
	getline(cin, line);
	rep(i, 13, sz(line)) {
		set<char> s;
		rep(j, i-13, i+1) {
			s.insert(line[j]);
		}
		if (sz(s) == 14) {
			printf("%d\n", i+1);
			return 0;
		}
	}
}
