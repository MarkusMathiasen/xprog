#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int t, n, k;
set<int> tickets;


int calc(int a, int b) {
	if (a < 1)a=1;
	if (a > k)a=k;
	if (b < 1)b=1;
	if (b > k)b=k;
	int big = *tickets.rbegin();
	int small = *tickets.begin();
	int ba = *(--tickets.upper_bound(a));
	int aa = *tickets.lower_bound(a);
	int bb = *(--tickets.upper_bound(b));
	int ab = *tickets.lower_bound(b);
	ii ra = ii((a+ba)/2+1, (a+aa+1)/2-1);
	ii rb = ii((b+bb)/2+1, (b+ab+1)/2-1);
	if (b > big)
		rb.second = k;
	if (b < small)
		rb.first = 1;
	if (a > big)
		ra.second = k;
	if (a < small)
		ra.first = 1;
	
	if (tickets.count(a))
		ra = ii(-10, -11);
	if (tickets.count(b))
		rb = ii(-7, -8);
	
	int res = ra.second-ra.first+1 + rb.second-rb.first+1;
	if (ra.first <= rb.first && ra.second >= rb.first)
		res -= ra.second-rb.first+1;
	if (rb.first <= ra.first && rb.second >= ra.first)
		res -= rb.second-ra.first+1;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n >> k;
		tickets.clear();
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			tickets.insert(x);
		}
		int wins = 0;

		calc(1, k);
		for (int a : tickets) {
			for (int b : tickets) {
				wins = max(wins, calc(a-1, b-1));
				wins = max(wins, calc(a-1, b+1));
				wins = max(wins, calc(a+1, b-1));
				wins = max(wins, calc(a+1, b+1));
			}
		}
		printf("Case #%d: %.6f\n", test, ((double)wins)/k);
	}
}
