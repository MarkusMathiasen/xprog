#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    while (T--){
        long long x, y; cin >> y >> x;
        long long result;
        if (x >= y){
            if (x % 2 == 1){
                result = x * x;
                result -= y-1;
            }
            else {
                result = (x-1) * (x-1);
                result += y;
            }
        }
        else {
            if (y % 2 == 0){
                result = y * y;
                result -= (x-1);
            }
            else {
                result = (y-1) * (y-1);
                result += x;
            }
        }
        cout << result << endl;
    }
}