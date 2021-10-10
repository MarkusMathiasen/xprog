#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<ll> partSums(n+1, 0);
    for (int i = 1; i <= n; i++)
        partSums[i] = partSums[i-1]+p[i-1];
    ll small = partSums[0];
    ll big = partSums[1];
    ll result = p[0];
    for (int i = 1; i <= n; i++){
        big = partSums[i];
        result = max(result, big - small);
        small = min(small, partSums[i]);
    }
    cout << result << endl;
}