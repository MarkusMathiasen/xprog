#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> mod(n, a[0] % n);
    for (int i = 0; i < n; i++){
        mod[i] = (mod[i-1]+a[i]) % n;
        if (mod[i] < 0) mod[i] = n + mod[i];
    }
    map<int, ll> m; m[0] = 1;
    ll result = 0;
    for (int i = 0; i < n; i++){
        int target = mod[i];
        if (m.count(target))
            result += m[target];
        if (m.count(mod[i]))
            m[mod[i]]++;
        else 
            m[mod[i]] = 1;
    }
    cout << result << endl;
}