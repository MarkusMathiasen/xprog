#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
vector<vector<double>> probs;
vector<double> dp;
ll facts[19];

void calcNextStates(ll state){
    ll fishCount = __builtin_popcount(state);
    ll comb = facts[fishCount] / (facts[fishCount -2] * 2);
    for (ll i = 0; i < n-1; i++){
        if (!(state & (1 << i))) continue;
        for (ll j = i+1; j < n; j++){
            if (!(state & (1 << j))) continue;
            ll eatI = state & ~(1 << i);
            ll eatJ = state & ~(1 << j);
            dp[eatI] += (probs[j][i] * dp[state]) / comb;
            dp[eatJ] += (probs[i][j] * dp[state]) / comb;
        }
    }
}

void prllState(ll n){
    for (ll i = 4; i >= 0; i--)
        cout << ((n >> i) & 1);
    cout << endl;
}

void perms(ll state, ll L, ll place){
    if (__builtin_popcount(state) == L){
        calcNextStates(state);
        return;
    }
    if (place == n) return;
    for (ll i = place; i < n; i++){
        perms(state | (1 << i), L, i+1);
    }
}

int main(){
    cin >> n;
    probs.assign(n, vector<double>(n, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> probs[i][j];
    ll state = (1 << n) - 1;
    dp.assign((1 << n), 0);
    dp[state] = 1;
    ll fact = 1; facts[0] = 1;
    for (ll i = 1; i < 19; i++){
        fact *= i;
        facts[i] = fact;
    }

    for (ll L = n; L > 1; L--){
        perms(0, L, 0);
    }

    for (ll i = 0; i < n; i++)
        cout << dp[(1 << i)] << " ";
    cout << endl;
}