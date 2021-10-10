/*
ID: markus3
TASK: msquare
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("msquare.out");
ifstream fin ("msquare.in");

pair<int, string> dp[8][8][8][8][8][8][8][8];
int state[8] = {1, 2, 3, 4, 5, 6, 7, 8};

int[] transA(int s[]){
    for (int i = 0; i < 4; i++){
        int temp = s[7-i];
        s[7-i] = s[i];
        s[i] = temp;
    }
}
void transB(int s[]){
    int x[8];
    for (int i = 0; i < 8; i++)
        x[i] = s[i];
    s[0] = x[3];
    for (int i = 1; i < 4; i++)
        s[i] = x[i-1];
    for (int i = 4; i < 7; i++)
        s[i] = x[i+1];
    s[7] = x[4];
}
void transC(int s[])

int main() {
    cout << state[0] << endl;
    transB(state);
    cout << state[0] << endl;
}