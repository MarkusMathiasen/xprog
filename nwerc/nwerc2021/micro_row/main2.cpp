#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

struct obj {
	int p;
	int s;
	int pos;
	int row;
};

int main() {
	int n; scanf("%d", &n);
	vector<obj> A(n, obj());
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &A[i].p, &A[i].s);
		A[i].pos = i;
	}
	sort(A.begin(), A.end(), [](const obj& a, const obj& b){
		return a.p < b.p;
	});
	set<ii> rows;
	for (obj& m : A) {
		if (!rows.size() || (*rows.begin()).first > m.s) {
			m.row = rows.size()+1;
			rows.insert(ii(m.s, m.row));
		}
		else {
			auto it = --rows.upper_bound(ii(m.s, n+1));
			m.row = (*it).second;
			rows.erase(it);
			rows.insert(ii(m.s, m.row));
		}
	}
	sort(A.begin(), A.end(), [](const obj& a, const obj& b) {
		return a.pos < b.pos;
	});
	for (obj& m : A)
		printf("%d ", m.row);
	printf("\n");
}
