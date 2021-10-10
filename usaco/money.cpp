/*
ID: markus3
TASK: money
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ofstream fout ("money.out");
ifstream fin ("money.in");

ll V, N;
vector<ll> coins;
ll dp[10001][25];

ll combs(ll n, ll pos){
    if (pos == -1) return 0;
    if (dp[n][pos] != -1) return dp[n][pos];
    if (coins[pos] > n) return dp[n][pos] = combs(n, pos-1);
    ll result = 0;
    result += combs(n, pos-1);
    result += combs(n-coins[pos], pos);
    return dp[n][pos] = result;
}

int main() {
    fin >> V >> N;
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < 25; i++) dp[0][i] = 1;
    coins.assign(V, 0);
    for (ll i = 0; i < V; i++)
        fin >> coins[i];
    sort(coins.begin(), coins.end());
    fout << combs(N, V-1) << endl;
}