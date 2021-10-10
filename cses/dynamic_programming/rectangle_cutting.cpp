#include <bits/stdc++.h>

using namespace std;

int a, b;
int dp[501][501];

int main(){
    scanf("%d %d", &a, &b);
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            dp[i][j] = i == j ? 0 : -1;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++){
            if (dp[i][j] != -1) continue;
            int result = INT_MAX;
            for (int k = 1; k < i; k++)
                result = min(result, dp[i-k][j]+dp[k][j]+1);
            for (int k = 1; k < j; k++)
                result = min(result, dp[i][j-k]+dp[i][k]+1);
            dp[i][j] = result;
        }
    printf("%d\n", dp[a][b]);
}