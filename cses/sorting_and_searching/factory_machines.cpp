#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, t;
vector<int> k;

bool isEnough(ll time){
    ll prods = 0;
    for (int i = 0; i < n; i++){
        prods += time / k[i];
        if (prods < 0) return true;
    }
    return (prods >= t);
}

int main(){
    cin >> n >> t;
    k.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    ll lower = 1;
    ll upper = 1000000000000000000;
    while (lower != upper){
        ll mid = (lower+upper)/2;
        if (isEnough(mid))
            upper = mid;
        else 
            lower = mid+1;
    }
    cout << lower << endl;
}