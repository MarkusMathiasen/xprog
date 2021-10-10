#include <bits/stdc++.h>
using namespace std;

int s, n, m;
vector<int> A;

bool isPeak(int x, int n, bool (*comp)(int, int)) {
	if (x < n-1 || x+n-1 >= s)
		return false;
	bool res = true;
	int last = A[x-n+1];
	for (int i = x-n+1; i <= x; i++)
		res &= comp(last, A[i]), last = A[i];
	for (int i = x; i < x+n; i++)
		res &= comp(A[i], last), last = A[i];
	return res;
}

int main() {
	scanf("%d%d%d", &s, &n, &m);
	A.assign(s, 0);
	for (int i = 0; i < s; i++)
		scanf("%d", &A[i]);
	int peaks = 0;
	for (int i = 0; i < s; i++)
		peaks += isPeak(i, n, [](int a, int b){return a <= b;});
	int valleys = 0;
	for (int i = 0; i < s; i++)
		valleys += isPeak(i, m, [](int a, int b){return a >= b;});
	printf("%d %d\n", peaks, valleys);
}
