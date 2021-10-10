/*
ID: markus3
TASK: game1
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
ofstream fout ("game1.out");
ifstream fin ("game1.in");

int n, s[101], dp[101][101];
int ps[101];

int sum(int a, int b) {return ps[b]-ps[a-1];}

int main(){
	fin >> n;
	for (int i = 1; i <= n; i++)
		fin >> s[i];
	for (int i = 1; i <= n; i++){
		ps[i] = ps[i-1]+s[i];
		dp[i][i] = s[i];
	}
	for (int diff = 1; diff < n; diff++){
		for (int start = 1, end = 1+diff; end <= n; start++, end++){
			int all = sum(start, end);
			int p2 = min(dp[start][end-1], dp[start+1][end]);
			dp[start][end] = all-p2;
		}
	}
	fout << dp[1][n] << " " << min(dp[1][n-1], dp[2][n]) << endl;
}
