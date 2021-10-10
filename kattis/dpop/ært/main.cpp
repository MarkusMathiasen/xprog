#include <bits/stdc++.h>
using namespace std;

int M, N, S;
vector<vector<int>> dp;

// fra first + til og med hvilken seng hun skal sove på skal returneres.
int cut(int m, int n) {
	// m er hvor mange senge der er tilbage, og n er hvor mange dage der er tilbage
	if (m <= n+1)
		return 0;
	if (n <= 0)
		return -1;
	if (dp[m][n] != -2)
		return dp[m][n];
	for (int i = 0; i <= m/2; i++)
		if (cut(i+1, n-1-S) != -1 && cut(m-(i+1), n-1) != -1)
			return dp[m][n] = i;
	return dp[m][n] = -1;
}

int main() {
	cin >> M >> N >> S;
	dp.assign(M+1, vector<int>(N+1, -2));
	int first = 0;
	while (M > 1) {
		int num = cut(M, N);
		cout << "?";
		for (int i = 0; i <= num; i++)
			cout << " " << first+i;
		cout << endl;
		int ans; cin >> ans;
		if (ans) {
			N -= 1+S;
			M = num+1;
		}
		else {
			N--;
			M -= num+1;
			first += num+1;
		}
	}
	cout << "! " << first << endl;
/*
first = 2
2, 3, 4, 5
num = 3
first = 6
*/

}
