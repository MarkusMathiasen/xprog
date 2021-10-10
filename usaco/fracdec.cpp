/*
ID: markus3
TASK: fracdec
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");

int N, D;
vector<int> number;
int rest;
int usedRest[100001];
int startPar = -1;

bool calcNext(){
    if (usedRest[rest] != -1){
        startPar = usedRest[rest];
        return false;
    }
    usedRest[rest] = number.size();
    rest *= 10;
    number.push_back(rest / D);
    rest %= D;
    if (rest == 0) return false;
    return true;
}

int main() {
    memset(usedRest, -1, sizeof(usedRest));
    fin >> N >> D;
    rest = N % D;
    fout << N / D << '.';
    int length = 1;
    for (int i = 10; (N/D) / i; i *= 10)
        length++;
    while (calcNext()) continue;
    for (int i = 0; i < number.size(); i++){
        if (startPar == i) fout << '(';
        fout << number[i];
        if ((i+length+3) % 76 == 0) fout << endl;
    }
    if (startPar > -1) fout << ')';
    fout << endl;
}