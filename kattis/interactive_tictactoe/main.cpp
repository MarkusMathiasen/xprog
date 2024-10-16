#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int read_state() {
	string tmp, board = "";
	rep(i, 0, 3) {
		cin >> tmp;
		board += tmp;
	}
	int res = 0;
	rep(i, 0, 9) {
		if (board[i] == 'x')
			res |= 1<<i;
		else if (board[i] == 'o')
			res |= 1<<(i+9);
	}
	return res;
}

void print_state(int state) {
	//printf("\n");
	rep(i, 0, 9) {
		if (state & (1<<i)) printf("x");
		else if (state & (1<<(i+9))) printf("o");
		else printf(".");
		if ((i+1)%3 == 0) printf("\n");
	}
	//printf("\n");
	fflush(stdout);
}

int is_done(int s) { // 3 if we are winning; 2 if draw; 1 if other winning; 0 = unfinished
	int state = s;
	rep(p, 0, 2) {
		rep(i, 0, 3) {
			// rows
			if (state & (1<<(3*i+0)) && state & (1<<(3*i+1)) && state & (1<<(3*i+2)))
				return 3-2*p;
			// cols
			if (state & (1<<(i+3*0)) && state & (1<<(i+3*1)) && state & (1<<(i+3*2)))
				return 3-2*p;
		}
		// diag 1
		if (state & 1 && state & (1<<4) && state & (1 << 8))
			return 3-2*p;
		// diag 2
		if (state & (1<<2) && state & (1<<4) && state & (1 << 6))
			return 3-2*p;
		
		state >>= 9;
	}
	bool finished = true;
	rep(i, 0, 9) finished &= s & (1<<i) || s & (1<<(i+9));
	if (finished) return 2;
	else return 0;
}

int dp[1<<18], play[1<<18]; // 3 = winning; 2 = draw; 1 = loosing; 0 = unknown;


int calc(int s) {
	if (dp[s]) return dp[s];
	int done = is_done(s);
	if (done) return dp[s] = done;
	rep(i, 0, 9) {
		if (s&(1<<i) || s&(1<<(i+9))) continue;
		s |= 1<<i;
		int worst = 4;
		rep(j, 0, 9) {
			if (s&(1<<j) || s&(1<<(j+9))) continue;
			int nxt = calc(s|(1<<(j+9)));
			worst = min(worst, nxt);
		}
		s ^= 1<<i;
		if (worst == 4) {
			play[s] = s|(1<<i);
			return dp[s] = is_done(s|(1<<i));
		}
		if (worst > dp[s]) {
			dp[s] = worst;
			play[s] = s|(1<<i);
		}
	}
	return dp[s];
}

int go(int s) {
	int done = is_done(s);
	if (done) return done;
	s = play[s];
	print_state(s);
	done = is_done(s);
	if (done) return done;
	s = read_state();
	//printf("%d\n", dp[s]);
	return go(s);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string order; cin >> order;
	int state = read_state();
	calc(state);
	go(state);
}
