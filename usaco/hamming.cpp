/*
ID: markus3
TASK: hamming
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int N, B, D;
vector<int> results(1);

bool isValid(int i){
    for (int curNum = 0; curNum < results.size(); curNum++){
        int diffs = 0;
        for (int k = 0; k < B; k++)
            if ((results[curNum] & (1 << k)) != (i & (1 << k)))
                diffs++;
        if (diffs < D) return false;
    }
    return true;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    fin >> N >> B >> D;
    int combs = pow(2, B+1);
    for (int i = 1; i < combs; i++)
        if (isValid(i))
            results.push_back(i);
    
    int printed = 0;
    for (int i = 0; i < N; i++){
        if (printed == 10) {printed = 0; fout << endl;}
        if (printed != 0) fout << " ";
        fout << results[i];
        printed++;
    }
    fout << endl;
}