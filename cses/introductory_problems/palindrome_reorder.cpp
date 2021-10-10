#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> letters(26, 0);
    char c;
    while (cin >> c){
        int n = (int)c - 65;
        letters[n]++;
    }
    int mid = -1;
    for (int i = 0; i < 26; i++){
        if (letters[i] % 2 == 1){
            if (mid == -1)
                mid = i;
            else 
                mid = -2;
        }
    }
    if (mid == -2){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < letters[i] / 2; j++)
            cout << (char)(i+65);
    }
    if (mid != -1) cout << char(mid+65);
    for (int i = 25; i >= 0; i--)
        for (int j = 0; j < letters[i] / 2; j++)
            cout << (char(i+65));
    cout << endl;

}