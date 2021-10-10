/*
ID: markus3
TASK: test
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("test.out");
ifstream fin ("test.in");

int main() {
    int a, b;
    fin >> a >> b;
    fout << (float)a/b << endl;
    fout << (float)a*2/(b*2);
}