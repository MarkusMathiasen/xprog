#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct que {
	ll x;
	string s;
	ll t;

	que() {}
	que(const ll& x, const string& s) : x(x), s(s) {}

	bool operator > (const que& a) const {
		if (s != a.s)
			return s > a.s;
		return x > a.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, k; cin >> n >> m >> k;
	string s; getline(cin, s);
	priority_queue<que, vector<que>, greater<que>> pq;
	for (ll i = 0; i < n; i++) {
		que book;
		getline(cin, s, '"');
		getline(cin, book.s, '"');
		cin >> book.x;
		pq.push(book);
	}
	vector<que> q;
	for (ll i = 0; i < m; i++) {
		que book;
		cin >> book.t;
		getline(cin, s, '"');
		getline(cin, book.s, '"');
		cin >> book.x;
		q.push_back(book);
	}
	sort(q.begin(), q.end(), [](const que& a, const que& b) {
		return a.t > b.t;
	});
	pq.push(que(k, "Jane Eyre"));
	ll tim = 0;
	while (true) {
		while (!q.empty() && q.back().t <= tim) {
			pq.push(q.back());
			q.pop_back();
		}
		tim += pq.top().x;
		if (pq.top().s == "Jane Eyre")
			break;
		pq.pop();
	}
	cout << tim << endl;
}
