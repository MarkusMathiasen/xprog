#include <bits/stdc++.h>

using namespace std;

long long calcRes(long long n){
    return (n*(n*n*n-(4*n-6))+(2*n-2)+(4*n-6)-(n*n*(n*n+1)/2));
}

int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cout << calcRes(i) << endl;
}