#include <bits/stdc++.h>

using namespace std;

int a, b;

bool tooMuch(int guess){
    int na = a, nb = b;
    na -= guess;
    nb -= guess*2;
    na -= nb*2;
    return (na >= 0);
}

int main(){
    int T; cin >> T;
    while (T--){
        a, b; cin >> a >> b;
        int lower = 0;
        int upper = min(a, b);
        while (lower != upper){
            int mid = (lower+upper)/2;
            if (tooMuch(mid))
                upper = mid;
            else 
                lower = mid+1;
        }
        a -= lower;
        b -= lower*2;
        a -= 2*b;
        if (a == 0)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}