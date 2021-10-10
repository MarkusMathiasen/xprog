#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
int mod = 1000000007;
 
int main(){
    int n, x; scanf("%d %d", &n, &x);
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++){
        for (int c : coins){
            if (i - c >= 0)
                dp[i] += dp[i - c];
        }
        dp[i] %= mod;
    }
    printf("%d\n", dp[x]);
}