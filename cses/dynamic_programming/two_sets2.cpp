#include <bits/stdc++.h>

using namespace std;

int n, mod = 1e9+7;
int dp[501][62626];

int calcWays(int x, int s){
    if (s < 0) return 0;
    if (dp[x][s] != -1) return dp[x][s];
    int result = 0;
    result += calcWays(x+1, s);
    result += calcWays(x+1, s-x);
    if (result >= mod) result -= mod;
    return dp[x][s] = result;
}

int main(){
    scanf("%d", &n);
    int sum = (n+1)*n / 2;
    if (sum % 2 != 0)
        {printf("0\n"); return 0;}
    int target = sum / 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= target; j++)
            dp[i][j] = -1;
    dp[n][n] = 1;
    for (int i = n-1; i > 0; i--)
        for (int j = 0; j <= target; j++)
            dp[i][j] = dp[i+1][j]+(j - i >= 0 ? dp[i+1][j-i] : 0),dp[i][j] -= dp[i][j] >= mod ? mod : 0;
    int result = dp[1][target];
    printf("%d\n", result);
}