/*
ID: markus3
TASK: fact4
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("fact4.out");
ifstream fin ("fact4.in");

int main() {
    int N; fin >> N;
    int n = 1;
    for (int i = 1; i <= N; i++){
        n *= i;
        while (n % 10 == 0) n /= 10;
        n = n % 100000;
        // cout << i << ": " << (n % 10) << endl;
    }
    fout << (n % 10) << endl;
}