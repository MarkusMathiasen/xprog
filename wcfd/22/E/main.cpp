#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> is;

int m;
int max_val;
int cnt = 0;

map<string, int> ptoi;
vector<is> A; // how much they have bought

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	while (m--) {
		string u, v; int d; cin >> u >> v >> d;
		if (!ptoi.count(u))
			ptoi[u] = cnt++,
			A.push_back(is(0, u));
		if (!ptoi.count(v))
			ptoi[v] = cnt++,
			A.push_back(is(0, v));
		A[ptoi[u]].first += d;
		A[ptoi[v]].first -= d;
	}
	sort(A.begin(), A.end());
	int rec = A.size()-1, buy = 0;
	while (buy < rec) {
		if (A[buy].first == 0) {
			buy++;
			continue;
		}
		if (A[rec].first == 0) {
			rec--;
			continue;
		}
		int am = min(abs(A[buy].first), A[rec].first);
		cout << A[buy].second << " " << A[rec].second << " " << am << "\n";
		A[buy].first += am;
		A[rec].first -= am;
	}
	cout << "settled\n";
}
