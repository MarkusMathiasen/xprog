#include <bits/stdc++.h>

using namespace std;

vector<bool> inSet;

int main(){
    long long n; cin >> n;
    if (n % 4 == 1 || n % 4 == 2){
        cout << "NO" << endl;
        return 0;
    }
    inSet.assign(n+1, 0);
    long long sum = n*(n+1) / 4;
    int inSetCount = 0;
    for (int i = n; i > 0; i--)
        if (sum >= i)
            sum -= i, inSet[i] = true, inSetCount++;
    cout << "YES" << endl;
    cout << inSetCount << endl;
    for (int i = 1; i <= n; i++)
        if (inSet[i])
            cout << i << " "; 
    cout << endl;
    cout << n - inSetCount << endl;
    for (int i = 1; i <= n; i++)
        if(!inSet[i])
            cout << i << " ";
    cout << endl;
}