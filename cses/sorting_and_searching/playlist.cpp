#include <bits/stdc++.h>

using namespace std;

map<int, bool> m;
int n;
int L = -1;
vector<int> k;

void pushLeft(int target){
    L++;
    while (k[L] != target){
        m[k[L]] = false;
        L++;
    }
    m[k[L]] = false;
}

int main(){
    cin >> n;
    k.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> k[i];
        m[k[i]] = false;
    }
    
    
    int result = 0;
    for (int R = 0; R < n; R++){
        if (m[k[R]] == true)
            pushLeft(k[R]);
        m[k[R]] = true;
        result = max(result, R-L);
    }
    cout << result << endl;
}