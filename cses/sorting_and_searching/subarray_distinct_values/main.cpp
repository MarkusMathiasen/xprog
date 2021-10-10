#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A;

int main() {
	scanf("%d %d", &n, &k);
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf(" %d", &A[i]);
	long long res = 0;
	int l = 0;
	int r = 0;
	map<int, int> m;
	m[A[0]] += 1;
	int diff = 1;
	while(l < n) {
		while(r < n-1) {
			if (m[A[r+1]])
				m[A[r+1]]++, r++;
			else if (diff < k)
				m[A[r+1]]++, diff++, r++;
			else
				break;
		}
		res += r-l+1;
		m[A[l]]--;
		if (m[A[l]] == 0)
			diff--;
		l++;
	}
	printf("%lld\n", res);
}
