#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

int main(){
    int n; cin >> n;
    int result = 1;
    for (int i = 0; i < n; i++){
        result = result << 1;
        result %= mod;
    }
    cout << result << endl;
}