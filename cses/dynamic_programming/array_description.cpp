#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m, p[100000];
int mod = 1e9+7;
ll dp[100000][102];

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    if (!p[0])
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    else 
        dp[0][p[0]] = 1;
    for (int i = 1; i < n; i++){
        if (p[i]){
            dp[i][p[i]] += dp[i-1][p[i]];
            dp[i][p[i]] += dp[i-1][p[i]-1];
            dp[i][p[i]] += dp[i-1][p[i]+1];
            while (dp[i][p[i]] >= mod) dp[i][p[i]] -= mod;
            continue;
        }
        for (int j = 1; j <= m; j++){
            dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            while (dp[i][j] >= mod) dp[i][j] -= mod;
        }
    }
    ll result = 0;
    for (int i = 0; i <= m; i++)
        result += dp[n-1][i];
    result %= mod;
    printf("%lld\n", result);
}