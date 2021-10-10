/*
ID: markus3
TASK: comehome
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("comehome.out");
ifstream fin ("comehome.in");

int P;
map<char, int> cToI;
map<int, char> iToC;
vector<vector<pair<int, int>>> graph;
int dist[52];

int main() {
    for (int i = 0; i < 26; i++){
        char c = (char)(i+97);
        cToI[c] = i+26;
        c = (char) (i+65);
        cToI[c] = i;
        iToC[i] = c;
    }
    graph.assign(52, vector<pair<int, int>>());
    fin >> P;
    for (int i = 0; i < P; i++){
        char c1; fin >> c1; int n1 = cToI[c1];
        char c2; fin >> c2; int n2 = cToI[c2];
        int d; fin >> d;
        graph[n1].push_back(make_pair(d, n2));
        graph[n2].push_back(make_pair(d, n1));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, 25));
    memset(dist, -1, sizeof(dist));
    int bestN = -1;
    while(!Q.empty()){
        int d = Q.top().first;
        int n = Q.top().second;
        Q.pop();
        if (dist[n] != -1) continue;
        dist[n] = d;
        if (bestN == -1 && n < 25) bestN = n;
        for (int i = 0; i < graph[n].size(); i++)
            Q.push(make_pair(d+graph[n][i].first, graph[n][i].second));
    }
    fout << iToC[bestN] << " " << dist[bestN] << endl;
}