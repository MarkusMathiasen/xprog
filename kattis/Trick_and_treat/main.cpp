#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> A;

int sim(int candy) {
	int res = 0;
	for (int r : A)
		if (r > candy)
			res++;
		else
			candy -= r;
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int res = n;
	for (int i = m-10; i <= m; i++)
		res = min(res, sim(i));
	printf("%d\n", res);
}
