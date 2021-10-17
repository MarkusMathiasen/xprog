#include <bits/stdc++.h>
using namespace std;

map<int, int> f, pos;
vector<int> A;
int n, c;

int main() {
	scanf("%d%d", &n, &c);
	A.assign(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		if (!pos[A[i]])
			pos[A[i]] = i+1;
		f[A[i]]++;
	}
	sort(A.begin(), A.end(), [](int const& a, int const& b) {
		if (f[a] != f[b])
			return f[a] > f[b];
		return pos[a] < pos[b];
	});
	for (int x : A)
		printf("%d ", x);
	printf("\n");
}	
