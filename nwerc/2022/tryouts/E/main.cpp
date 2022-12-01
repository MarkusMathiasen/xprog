#include <bits/stdc++.h>
using namespace std;

int A[1<<10][1<<10];
int cnt[1<<20];
bool vis[1<<20];
int n, ccnt;

bool validate(int i, int j) {
	if (i+1 >= 1<<n)
		return false;
	if (j+1 < 1<<n) {
		if (A[i][j] == A[i+1][j] && A[i][j] == A[i][j+1])
			return true;
		if (A[i][j] == A[i+1][j] && A[i][j] == A[i+1][j+1])
			return true;
		if (A[i][j] == A[i][j+1] && A[i][j] == A[i+1][j+1])
			return true;
	}
	if (j > 0 && A[i][j] == A[i+1][j] && A[i][j] == A[i+1][j-1])
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ccnt = ((1<<(2*n))-1)/3;
	for (int i = 0; i < 1<<n; i++)
		for (int j = 0; j < 1<<n; j++) {
			cin >> A[i][j];
			cnt[A[i][j]]++;
		}
	int res = 1;
	for (int i = 1; i <= ccnt; i++)
		res &= cnt[i] == 3;
	vis[0] = true;
	for (int i = 0; i < 1<<n; i++)
		for (int j = 0; j < 1<<n; j++) {
			if (vis[A[i][j]])
				continue;
			vis[A[i][j]] = true;
			res &= validate(i, j);
		}
	printf("%d\n", res);
}
