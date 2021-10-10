#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; bool isStart = true;
    while (getline(cin, s)){
        for (int i = 0; i < s.size(); i++){
            if (s.at(i) == '"'){
                if (isStart){
                    isStart = false;
                    cout << "``";
                }
                else{
                    isStart = true;
                    cout << "''";
                }
            }
            else cout << s.at(i);
        }
        cout << endl;
    }
}