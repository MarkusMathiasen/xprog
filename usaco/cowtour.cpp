/*
ID: markus3
TASK: cowtour
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("cowtour.out");
ifstream fin ("cowtour.in");

struct point{
    int x, y;
};
vector<point> coor;
int N;
vector<vector<int>> graph;
vector<int> comp;
vector<double> l;

void findComp(int start, int c){
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        if (comp[v] != -1) continue;
        comp[v] = c;
        for (int i = 0; i < graph[v].size(); i++)
            Q.push(graph[v][i]);
    }
}

double dist(int n1, int n2){
    double a = coor[n2].x-coor[n1].x;
    double b = coor[n2].y-coor[n1].y;
    return (sqrt(a*a+b*b));
}


double maxL(int start){
    double result = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
    vector<bool> vis(N, 0);
    Q.push(make_pair(0, start));
    while (!Q.empty()){
        double d = Q.top().first;
        int n = Q.top().second;
        Q.pop();
        if (vis[n]) continue;
        vis[n] = true;
        if (result < d) result = d;
        for (int i = 0; i < graph[n].size(); i++)
            Q.push(make_pair(d+dist(n, graph[n][i]), graph[n][i]));
    }
    return result;
}

int main() {
    fin >> N;
    coor.assign(N, point());
    for (int i = 0; i < N; i++){
        fin >> coor[i].x;
        fin >> coor[i].y;
    }
    graph.assign(N, vector<int>());
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            char c; fin >> c;
            if (c == '1')
                graph[i].push_back(j);
        }
    }
    comp.assign(N, -1);
    for (int i = 0; i < N; i++)
        findComp(i, i);
    l.assign(N, 0);
    for (int i = 0; i < N; i++)
        l[i] = maxL(i);
    double result = 2000000000;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (comp[j] == comp[i]) continue;
            result = min(result, l[i]+l[j]+dist(i, j));
        }
    }
    fout << fixed;
    fout << setprecision(6);
    fout << result << endl;
    cout << dist(104, 68) << endl;
}