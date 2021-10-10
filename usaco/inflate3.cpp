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

int M, N;
vector<ii> type;
int dp[10001];

int main() {
    fin >> M >> N;
    type.assign(N, ii(0, 0));
    for (int i = 0; i < N; i++){
        fin >> type[i].first;    //Points  (Value)
        fin >> type[i].second;   //Minutes (Cost)
    }
    for (int i = 0; i <= M; i++){
        int result = 0;
        for (int j = 0; j < N; j++){
            if (i-type[j].second < 0) continue;
            result = max(result, type[j].first+dp[i-type[j].second]);
        }
        dp[i] = result;
    }
    fout << dp[M] << endl;
}