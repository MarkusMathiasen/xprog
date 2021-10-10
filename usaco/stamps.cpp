/*
ID: markus3
TASK: stamps
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("stamps.out");
ifstream fin ("stamps.in");

int need[2000001];
int K, N;
int best = 0;
vector<int> stamps;

int main() {
    memset(need, 100, sizeof(need));
    need[0] = 0;
    fin >> K >> N;
    stamps.assign(N, 0);
    for (int i = 0; i < N; i++)
        fin >> stamps[i];
    for (int i = 0; i < 2000001; i++)
        for (int j = 0; j < N; j++){
            if (i+stamps[j] > 2000000) break;
            need[i+stamps[j]] = min(need[i+stamps[j]], need[i]+1);
        }
    need[0] = 1000;
    int start, slut;
    for (int i = 0; i < 2000001; i++){
        int length = 0;
        int tempStart = i;
        while (need[i] <= K) {length++; i++;}
        best = max(best, length);
    }
    fout << best << endl;
}