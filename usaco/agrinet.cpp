/*
ID: markus3
TASK: agrinet
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

ofstream fout ("agrinet.out");
ifstream fin ("agrinet.in");

int vis[100];
vector<vector<int>> adjMat;
int N;

int main() {
    fin >> N;
    adjMat.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> adjMat[i][j];
    memset(vis, false, sizeof(vis));
    int result = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, 0));
    while (!Q.empty()){
        int d = Q.top().first;
        int n = Q.top().second;
        Q.pop();
        if (vis[n]) continue;
        vis[n] = true;
        result += d;
        for (int i = 0; i < N; i++)
            Q.push(ii(adjMat[n][i], i));
    }
    fout << result << endl;
}