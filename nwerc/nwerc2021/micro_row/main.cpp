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
	vector<int> rows;
	for (obj& m : A) {
		if (!rows.size() || rows.back() > m.s) {
			rows.push_back(m.s);
			m.row = rows.size();
		}
		else {
			int high = rows.size()-1;
			int low = 0;
			while (low < high) {
				int mid = (low+high)/2;
				if (rows[mid] > m.s)
					low = mid+1;
				else
					high = mid;
			}
			rows[low] = m.s;
			m.row = low+1;
		}
	}
	sort(A.begin(), A.end(), [](const obj& a, const obj& b) {
		return a.pos < b.pos;
	});
	for (obj& m : A)
		printf("%d ", m.row);
	printf("\n");
}
