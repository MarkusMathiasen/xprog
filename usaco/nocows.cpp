/*
ID: markus3
TASK: nocows
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ofstream fout ("nocows.out");
ifstream fin ("nocows.in");

ll N, K;
ll dp[2][101][201];

ll treeComb(ll e, ll k, ll n){              //e = need to reach end, k = maxHeight, n = number of cows to use
    if (dp[e][k][n] != -1) return dp[e][k][n];
    if (k == 0) return dp[e][k][n] = (n == 0 ? 1 : 0);
    if (e && k*2 > n) return dp[e][k][n] = 0;
    if (n == 0) return dp[e][k][n] = 1;
    n -= 2;
    ll combs = 0;
    if (e){
        for (ll i = 0; i <= n; i += 2){
            ll temp = treeComb(1, k-1, i);
            temp *= treeComb(0, k-1, n-i) - treeComb(1, k-1, n-i);
            temp *= 2;
            combs += temp;
        }
        for (ll i = 0; i <= n; i += 2){
            ll temp = treeComb(1, k-1, i);
            temp *= treeComb(1, k-1, n-i);
            combs += temp;
        }
        return dp[e][k][n+2] = combs % 9901;
    }
    else {
        for (ll i = 0; i <= n; i += 2){
            ll temp = treeComb(0, k-1, i);
            temp *= treeComb(0, k-1, n-i);
            combs += temp;
        }
        return dp[e][k][n+2] = combs % 9901;
    }
}

int main() {
    fin >> N >> K;
    memset(dp, -1, sizeof(dp));
    fout << (treeComb(1, K-1, N-1)) % 9901 << endl;
}