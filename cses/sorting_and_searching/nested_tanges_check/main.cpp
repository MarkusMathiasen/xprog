#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
#define s second
#define f first

int n;
vector<pair<ii, int>> r;
vector<int> minq, maxq;
vector<pair<int, bool>> inner, outer;

int main() {
	cin >> n;
	r.assign(n, pair<ii, int>(ii(0, 0), 0));
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &r[i].f.f, &r[i].f.s);
		r[i].s = i;
	}
	sort(r.begin(), r.end(), [](pair<ii, int> a, pair<ii, int> b) {
		if (a.f.f != b.f.f) return a.f.f < b.f.f;
		return a.f.s > b.f.s;
	});
	minq.assign(n, r[n-1].f.s);
	for(int i = n-2; i >= 0; i--)
		minq[i] = min(minq[i+1], r[i].f.s);
	maxq.assign(n, r[0].f.s);
	for (int i = 1; i < n; i++)
		maxq[i] = max(maxq[i-1], r[i].f.s);
	
	inner.assign(n, pair<int, bool>(0, 0));
	outer.assign(n, pair<int, bool>(0, 0));
	for (int i = 0; i < n; i++) {
		if (i != 0 && maxq[i-1] >= r[i].f.s)
			inner[i].s = 1;
		if (i != n-1 && minq[i+1] <= r[i].f.s)
			outer[i].s = 1;
		inner[i].f = r[i].s;
		outer[i].f = r[i].s;
	}
	sort(inner.begin(), inner.end());
	sort(outer.begin(), outer.end());
	for (pair<int, bool> i : outer)
		printf("%d ", i.s);
	printf("\n");
	for (pair<int, bool> i : inner)
		printf("%d ", i.s);
	printf("\n");
}
