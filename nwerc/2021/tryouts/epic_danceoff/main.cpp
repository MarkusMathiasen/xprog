#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	string s; getline(cin, s);
	vector<string> A(n, "");
	for (int i = 0; i < n; i++)
		getline(cin, A[i]);
	int res = 1;
	for (int col = 0; col < m; col++) {
		bool clear = true;
		for (int row = 0; row < n; row++)
			clear &= A[row][col] == '_';
		res += clear;
	}
	printf("%d\n", res);
}
