#include <bits/stdc++.h>
using namespace std;

int main(){
    int start, n1, n2, n3;
    cin >> start >> n1 >> n2 >> n3;
    while (start || n1 || n2 || n3){
        int result = 120;
        result += start < n1 ? (start+40-n1) : start-n1;
        result += n2 < n1 ? (n2+40-n1) : n2-n1;
        result += n2 < n3 ? (n2+40-n3) : n2-n3;
        cout << result*9 << endl;
        cin >> start >> n1 >> n2 >> n3;
    }
}