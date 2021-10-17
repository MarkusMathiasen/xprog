#include <bits/stdc++.h>
using namespace std;

int inv = 0;

vector<int> merge(vector<int> a, vector<int> b) {
	int ai = 0, bi = 0;
	vector<int> res;
	while (ai < (int)a.size() || bi < (int)b.size()) {
		if (ai >= (int)a.size())
			res.push_back(b[bi++]);
		else if (bi >= (int)b.size())
			res.push_back(a[ai++]);
		else if (b[bi] < a[ai])
			inv += a.size()-ai, res.push_back(b[bi++]);
		else if (a[ai] < b[bi])
			res.push_back(a[ai++]);
		else
			throw res;
	}
	return res;
}

vector<int> mergesort(vector<int> A) {
	int n = A.size();
	if (A.size() < 2)
		return A;
	vector<int> a(A.begin(), A.begin()+n/2);
	vector<int> b(A.begin()+n/2, A.end());
	a = mergesort(a);
	b = mergesort(b);
	return merge(a, b);
}

int main() {
	int n; scanf("%d", &n);
	vector<int> A(n, 0), m(n+1, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		m[x] = i+1;
	}
	for (int& x : A)
		x = m[x];
	mergesort(A);
	printf(inv%2 == 0 ? "Possible\n" : "Impossible\n");
}
