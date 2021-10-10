#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> ps(n, a[0]);
    for (int i = 1; i < n; i++)
        ps[i] = a[i]+ps[i-1];
    map<ll, ll> m; m[0] = 1;
    ll result = 0;
    for (int i = 0; i < n; i++){
        ll target = ps[i]-x;
        if (m.count(target))
            result += m[target];
        if (m.count(ps[i]))
            m[ps[i]]++;
        else 
            m[ps[i]] = 1;
    }
    cout << result << endl;
}