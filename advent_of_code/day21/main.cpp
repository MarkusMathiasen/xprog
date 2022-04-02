#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

ii dp[21][21][10][10][2];

ii rec(int s1, int s2, int p1, int p2, bool turn) {
	if (s1 >= 21)
		return ii(1, 0);
	else if (s2 >= 21)
		return ii(0, 1);
	if (dp[s1][s2][p1][p2][turn] != ii(-1, -1))
		return dp[s1][s2][p1][p2][turn];
	ii res = ii(0, 0);
	if (turn) {
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++) {
					p1 = (p1+i+j+k)%10;
					ii x = rec(s1+p1+1, s2, p1, p2, !turn);
					res.first += x.first;
					res.second += x.second;
					p1 = (p1-i-j-k+10)%10;
				}
	}
	else {
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++) {
					p2 = (p2+i+j+k)%10;
					ii x = rec(s1, s2+p2+1, p1, p2, !turn);
					res.first += x.first;
					res.second += x.second;
					p2 = (p2-i-j-k+10)%10;
				}
	}
	return dp[s1][s2][p1][p2][turn] = res;
}

int die = -1;
int dieCount = 0;
int roll() {
	dieCount++;
	die = (die+1)%100;
	return die+1;
}

int main() {
	int p1, p2;
	int s1 = 0, s2 = 0;
	scanf("Player 1 starting position: %d\n", &p1);
	scanf("Player 2 starting position: %d\n", &p2);
	p1--; p2--;
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					for (int m = 0; m < 2; m++)
						dp[i][j][k][l][m] = ii(-1, -1);
	ii x = rec(s1, s2, p1, p2, true);
	printf("%lld\n", max(x.first, x.second));
}
