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
	int n; cin >> n;
	string line;
	vector<deque<char>> A(n, deque<char>());
	getline(cin, line);
	while (getline(cin, line), line[1] != '1') {
		rep(i, 0, n) {
			if (isalpha(line[4*i+1]))
				A[i].push_back(line[4*i+1]);
		}
	}
	int k, a, b;
	while (cin >> line >> k >> line >> a >> line >> b) {
		a--, b--;
		deque<char> buf;
		rep(i, 0, k) {
			buf.push_front(A[a].front());
			A[a].pop_front();
		}
		rep(i, 0, k) {
			A[b].push_front(buf.front());
			buf.pop_front();
		}
	}
	for (deque<char> s : A)
		printf("%c", s.front());
	printf("\n");
}
