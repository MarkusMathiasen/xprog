#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pii h(0, 0);
vector<pii> t(9, pii(0, 0));
set<pii> s;

void fix(pii& h, pii& t) {
	if (h.first == t.first) {
		if (h.second > t.second)
			t.second = h.second-1;
		else if (h.second < t.second)
			t.second = h.second+1;
	} else if (h.second == t.second) {
		if (h.first > t.first)
			t.first = h.first-1;
		else if (h.first < t.first)
			t.first = h.first+1;
	} else if (abs(h.first-t.first) > 1 || abs(h.second-t.second) > 1){
		if (h.second > t.second)
			t.second++;
		else if (h.second < t.second)
			t.second--;
		if (h.first > t.first)
			t.first++;
		else if (h.first < t.first)
			t.first--;
	}
}

void fix() {
	fix(h, t[0]);
	rep(i, 1, 9)
		fix(t[i-1], t[i]);
	s.insert(t.back());
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	char c; int d;
	s.insert(t.back());
	while (scanf(" %c%d", &c, &d) != EOF) {
		rep(i, 0, d) {
			if (c == 'R') {
				h.second++;
			} else if (c == 'U') {
				h.first++;
			} else if (c == 'L') {
				h.second--;
			} else if (c == 'D') {
				h.first--;
			} else assert(false);
			fix();
		}
	}
	printf("%d\n", sz(s));
}
