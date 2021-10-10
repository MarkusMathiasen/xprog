#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
ll total = 0;
vector<ll> p;

ll cs(ll pos, ll sum){
    if (pos == n){
        ll other = total - sum;
        ll result = sum - other;
        if (result < 0) result = -result;
        return result;
    }
    ll take = cs(pos+1, sum+p[pos]);
    ll dont = cs(pos+1, sum);
    return min(take, dont);
}

int main(){
    cin >> n;
    p.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    for (ll i = 0; i < n; i++)
        total += p[i];
    cout << cs(0, 0) << endl;
}