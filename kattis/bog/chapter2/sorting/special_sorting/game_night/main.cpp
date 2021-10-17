#include <bits/stdc++.h>
using namespace std;

vector<int> nc(3, 0);
int n;
vector<char> A;
vector<vector<int>> partsum;

int sum(int c, int l, int r) {
	if (l > r+1 || r >= n)
		throw l;
	if (l == r+1)
		return 0;
	return partsum[c][r] - (l == 0 ? 0 : partsum[c][l-1]);
}

int main() {
	scanf("%d", &n);
	A.assign(n, ' ');
	partsum.assign(3, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		scanf(" %c", &A[i]);
		nc[A[i]-'A']++;
		partsum[A[i]-'A'][i]++;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 1; j < n; j++)
			partsum[i][j] += partsum[i][j-1];
	int res = n;
	vector<int> s = {0, 1, 2};
	do {
		for (int p1 = 0; p1 < nc[s[0]]; p1++) {
			int val = 0;
			val += p1+1 - sum(s[0], 0, p1);
			int p2 = p1+nc[s[1]];
			val += nc[s[1]] - sum(s[1], p1+1, p2);
			int p3 = p2 + nc[s[2]];
			val += nc[s[2]] - sum(s[2], p2+1, p3);
			val += nc[s[0]] - (p1+1) - sum(s[0], p3+1, n-1);
			res = min(res, val);
		}
	} while (next_permutation(s.begin(), s.end()));
	printf("%d\n", res);
}
