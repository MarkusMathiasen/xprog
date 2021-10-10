#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;
vector<int> a;

bool trySize(ll size){
    int used = 1;
    ll currSum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > size) return false;
        currSum += a[i];
        if (currSum > size){
            used++;
            currSum = a[i];
        }
    }
    return (used <= k);
}

int main(){
    cin >> n >> k;
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll upper = 1000000000000000;
    ll lower = 1;
    while (upper != lower){
        ll mid = (upper+lower) / 2;
        if (trySize(mid))
            upper = mid;
        else
            lower = mid+1;
    }
    cout << lower << endl;
}