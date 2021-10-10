#include <bits/stdc++.h>

using namespace std;

int sumMat[1001][1001];
int n, q;

int sum(int a, int b, int x, int y){
	int result = 0;
	result += sumMat[x][y];
	result -= sumMat[x][b-1];
	result -= sumMat[a-1][y];
	result += sumMat[a-1][b-1];
	return result;
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			char c; scanf(" %c", &c);
			if (c == '*') sumMat[i][j]++;
			sumMat[i][j] += sumMat[i][j-1];
			sumMat[i][j] += sumMat[i-1][j];
			sumMat[i][j] -= sumMat[i-1][j-1];
		}
	while (q--){
		int a, b, x, y; scanf("%d %d %d %d", &a, &b, &x, &y);
		printf("%d\n", sum(a, b, x, y));
	}
}
