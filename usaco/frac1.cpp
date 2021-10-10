/*
ID: markus3
TASK: frac1
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> fracs;
int N;

bool isDivisable(int t, int n){
    for (int i = 2; i <= t; i++)
        if (t % i == 0 && n % i == 0) return true;
    return false;
}

pair<int, int> findSmallest(){ //Will return index (and update the index to its new value)
    int n = 1;
    for (int i = 2; i <= N; i++)
        n = (fracs[n]/(float)n > fracs[i]/(float)i ? i : n);
    int t = fracs[n];
    do {fracs[n]++;} while(isDivisable(fracs[n], n));
    return pair<int, int> (t, n);
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    fin >> N;
    fracs.assign(N+1, 1); //Index er nævner value er tæller
    fout << "0/1" << endl;
    pair<int, int> nextFrac = findSmallest();
    while ((float)nextFrac.first / nextFrac.second < 1){
        fout << nextFrac.first << "/" << nextFrac.second << endl;
        nextFrac = findSmallest();
    }
    fout << "1/1" << endl;
}