#include <bits/stdc++.h>

using namespace std;

int n, x;
int price[1000], pages[1000];
int dp[1000][100001];

int main(){
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    for (int i = 0; i <= x; i++)
        dp[0][i] = i >= price[0] ? pages[0] : 0;
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= x; j++){
            if (price[i] > j){dp[i][j] = dp[i-1][j]; continue;}
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i]]+pages[i]);
        }
    }
    printf("%d\n", dp[n-1][x]);
}