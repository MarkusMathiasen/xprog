#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> A(n, -1), B(m, -1);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &B[i]);
	map<int, int> tim;
	for (int a : A)
		for (int b : B)
			if (a <= b)
				tim[b-a]++;
	int res = 0;
	int am = 0;
	for (auto& [k,v] : tim)
		if (v > am)
			am = v, res = k;
	printf("%d\n", res);
}
