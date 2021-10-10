/*
ID: markus3
TASK: inflate
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("inflate.out");
ifstream fin ("inflate.in");

#define ii pair<int, int>

int dp[10000][10000];
int M, N;
vector<ii> knap;

int calcBest(int pos, int minLeft){
    if (pos == N) return 0;
    if (dp[pos][minLeft] != -1) return dp[pos][minLeft];
    int p = knap[pos].first;
    int m = knap[pos].second;
    int stay = 0;
    if (m <= minLeft)
        stay = calcBest(pos, minLeft-m) + p;
    int leave = calcBest(pos+1, minLeft);
    return max(stay, leave);    
}

int main() {
    memset(dp, -1, sizeof(dp));
    fin >> M >> N;
    knap.assign(N, ii(0, 0));
    for (int i = 0; i < N; i++){
        fin >> knap[i].first;  //Points
        fin >> knap[i].second; //Minutes
    }
    fout << calcBest(0, M) << endl;
}