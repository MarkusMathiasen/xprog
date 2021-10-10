#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    vector<int> t(n, 0);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += t[i];
    ll result = sum;
    if (t.back() > sum-t.back())
        result += t.back()-(sum-t.back());
    cout << result << endl;
    
}