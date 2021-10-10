/*
ID: markus3
TASK: cowtour
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("cowtour.out");
ifstream fin ("cowtour.in");

int N;
vector<pair<int, int>> pos;
vector<vector<int>> graph;
vector<int> comps;
vector<double> l;


double dist(int n1, int n2){
    int x1 = pos[n1].first;
    int x2 = pos[n2].first;
    int dx = x2-x1;
    int y1 = pos[n1].second;
    int y2 = pos[n2].second;
    int dy = y2-y1;
    return sqrt(dx*dx+dy*dy);
}

void findComp(int start){
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()){
        int n = Q.front();
        Q.pop();
        if (comps[n] != -1) continue;
        comps[n] = start;
        for (int i = 0; i < graph[n].size(); i++)
            Q.push(graph[n][i]);
    }
}

double findL(int start){
    double result = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
    Q.push(make_pair(0, start));
    vector<bool> vis(N, false);
    while (!Q.empty()){
        double d = Q.top().first;
        int n = Q.top().second;
        Q.pop();
        if (vis[n]) continue;
        vis[n] = true;
        result = max(result, d);
        for (int i = 0; i < graph[n].size(); i++)
            Q.push(make_pair(d+dist(n, graph[n][i]), graph[n][i]));
    }
    return result;
}

int main() {
    fin >> N;
    pos.assign(N, pair<int, int>());
    for (int i = 0; i < N; i++)
        fin >> pos[i].first >> pos[i].second;
    graph.assign(N, vector<int>());
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            char c; fin >> c;
            if (c == '1')
                graph[i].push_back(j);
        }
    comps.assign(N, -1);
    for (int i = 0; i < N; i++)
        findComp(i);
    l.assign(N, 0);
    for (int i = 0; i < N; i++)
        l[i] = findL(i);
    double result = 0;
    for (int i = 0; i < N; i++)
        result = max(result, l[i]);
    double result2 = 2000000000;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (comps[i] == comps[j]) continue;
            result2 = min(result2, l[i]+l[j]+dist(i, j));
        }
    }
    fout << fixed;
    fout << setprecision(6);
    fout << max(result, result2) << endl;
}   