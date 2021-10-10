#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    while (n){
        int a, b; a = b = 0;
        bool aTurn = true;
        for (int i = 0; i < 32; i++){
            if (!(n & (1 << i))) continue;
            if (aTurn)
                a |= (1 << i);
            else
                b |= (1 << i);
            aTurn = !aTurn;
        }
        cout << a << " " << b << endl;
        cin >> n;
    }
}