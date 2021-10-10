#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>

int n, x;
vector<int> dp;

int main(){
    cin >> n >> x;
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    dp.assign(x+1, -1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++){
        int result = INT_MAX;
        for (int j = 0; j < n; j++){
            int prev = i - coins[j];
            if (prev < 0 || dp[prev] == -1) continue;
            result = min(result, dp[prev]+1);
        }
        if (result != INT_MAX)
            dp[i] = result;
    }
    cout << dp[x] << endl;
}