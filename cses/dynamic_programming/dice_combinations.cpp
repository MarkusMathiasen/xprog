#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<ll, ll>

int n; int mod = 1000000007;
vector<ll> dp;

ll combs(int sum){
    if (sum < 0) return 0;
    if (dp[sum] != -1) return dp[sum];
    ll result = 0;
    for (int i = 6; i > 0; i--)
        result += combs(sum-i);
    result %= mod;
    return dp[sum] = result;
}

int main(){
    cin >> n;
    dp.assign(n+1, -1);
    dp[0] = 1;
    cout << combs(n) << endl;
}