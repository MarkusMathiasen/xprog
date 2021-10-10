#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

map<int, int> m;
int n, pos;
vector<vector<int>> r;
vector<ii> inner, outer;
vector<int> vals, ft;

int sum(int i) {
	int res = 0;
	while (i > 0)
		res += ft[i], i -= i&(-i);
	return res;
}

void update(int i) {
	while (i < pos)
		ft[i] += 1, i += i&(-i);
}

int main() {
	cin >> n;
	r.assign(n, vector<int>{0, 0, 0});
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &r[i][0], &r[i][1]);
		r[i][2] = i;
		vals.push_back(r[i][1]);
	}
	sort(vals.begin(), vals.end());
	pos = 1;
	for (int i = 0; i < (int)vals.size(); i++) {
		if (!m[vals[i]])
			m[vals[i]] = pos++;
	}
	for (int i = 0; i < (int)r.size(); i++)
		r[i][1] = m[r[i][1]];
	
	sort(r.begin(), r.end(), [](vector<int>& a, vector<int>& b) {
		if (a[0] != b[0]) return a[0] < b[0];
		return a[1] > b[1];
	});

	outer.assign(n, ii(0, 0));
	inner.assign(n, ii(0, 0));

	ft.assign(pos, 0);
	for (int i = n-1; i >= 0; i--) {
		outer[i].first = r[i][2];
		outer[i].second = sum(r[i][1]);
		update(r[i][1]);
	}
	sort(outer.begin(), outer.end());
	ft.assign(pos, 0);
	for (int i = 0; i < n; i++) {
		inner[i].first = r[i][2];
		inner[i].second = i - sum(r[i][1]-1);
		update(r[i][1]);
	}
	sort(inner.begin(), inner.end());
	for (ii i : outer)
		printf("%d ", i.second);
	printf("\n");
	for (ii i : inner)
		printf("%d ", i.second);
	printf("\n");
}
