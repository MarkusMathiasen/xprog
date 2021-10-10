/*
ID: markus3
TASK: runround
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

long long N;

bool isRunround(long long i){
    vector<int> digets;
    int used = 0;
    while (i > 0){
        int next = i % 10;
        i /= 10;
        digets.push_back(next);
        if (used & (1 << next)) return false;
        used |= (1 << next);
    }
    reverse(digets.begin(), digets.end());
    int count = 0; int place = 0;
    do {
        int add = digets[place];
        while (add + place >= digets.size()) add -= digets.size();
        place += add;
        count++;
    } while (place && count <=digets.size());

    return (count == digets.size());
}

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    fin >> N; N++;
    while (!isRunround(N))
        N++;
    fout << N << endl;
}