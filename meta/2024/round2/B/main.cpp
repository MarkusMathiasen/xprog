#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
vector<string> board(6);

char smart() {
	rep(i, 0, 6) cin >> board[5-i];
	bool f_win = false, c_win = false;
	// algorithm

	// cols:
	rep(c, 0, 7) rep(r, 0, 3) {
		char x = board[r][c];
		bool all = true;
		rep(j, r+1, r+4) all &= board[j][c] == x;
		if (all) {
			if (x == 'F') f_win = true;
			else if (x == 'C') c_win = true;
			else assert(false);
			break;
		}
	}

	rep(c, 0, 4) {
		bool skip = false;
		// flat line bottom
		rep(r, 0, 3) {
			char x = board[r][c];
			bool all = true;
			rep(j, 1, 4) all &= board[r][c+j] == x;
			if (all) {
				if (x == 'F') f_win = true;
				else if (x == 'C') c_win = true;
				else assert(false);
				skip = true;
				break;
			}
		}
		if (skip) continue;
		// diag up
		rep(r, 0, 3) {
			char x = board[r][c];
			bool all = true;
			rep(j, 1, 4) all &= board[r+j][c+j] == x;
			if (all) {
				if (x == 'F') f_win = true;
				else if (x == 'C') c_win = true;
				else assert(false);
				skip = true;
				break;
			}
		}
		if (skip) continue;
		// diag down
		rep(r, 3, 6) {
			char x = board[r][c];
			bool all = true;
			rep(j, 1, 4) all &= board[r-j][c+j] == x;
			if (all) {
				if (x == 'F') f_win = true;
				else if (x == 'C') c_win = true;
				else assert(false);
				skip = true;
				break;
			}
		}
		if (skip) continue;
		// line top
		rep(r, 3, 6) {
			char x = board[r][c];
			bool all = true;
			rep(j, 1, 4) all &= board[r][c+j] == x;
			if (all) {
				if (x == 'F') f_win = true;
				else if (x == 'C') c_win = true;
				else assert(false);
				skip = true;
				break;
			}
		}
	}

	// algorithm done
	if (f_win && c_win) return '?';
	else if (f_win && !c_win) return 'F';
	else if (!f_win && c_win) return 'C';
	else if (!f_win && !c_win) return '0';
	else assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		char res = smart();
		printf("%c\n", res);
	}
}