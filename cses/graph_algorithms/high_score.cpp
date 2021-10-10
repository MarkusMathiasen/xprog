#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<int, int>

int n, m;
ll dist[2500], big = -1e16;
vector<vector<ii>> graph;

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<ii>());
    while (m--){
        int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
        graph[a].push_back(ii(b, c));
    }
    for (int i = 1; i < n; i++)
        dist[i] = big;
    for (int k = 0; k < n-1; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < graph[i].size(); j++){
                int u = graph[i][j].first;
                dist[u] = max(dist[u], dist[i] + graph[i][j].second);
            }
    vector<int> negCycs;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < graph[i].size(); j++){
            int u = graph[i][j].first;
            if (dist[i]+graph[i][j].second > dist[u])
                negCycs.push_back(i);
        }
    queue<int> Q;
    Q.push(0);
    bool newvis[n] = {false};
    while (!Q.empty()){
        int v = Q.front(); Q.pop();
        if (newvis[v]) continue;
        newvis[v] = true;
        for (int i = 0; i < graph[v].size(); i++)
            Q.push(graph[v][i].first);
    }
    
    for (int i = 0; i < negCycs.size(); i++)
        if (newvis[negCycs[i]]) Q.push(negCycs[i]);
    bool vis[n] = {false};
    while (!Q.empty()){
        int v = Q.front(); Q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (int i = 0; i < graph[v].size(); i++)
            Q.push(graph[v][i].first);
    }

    if (vis[n-1]) {printf("-1\n"); return 0;}
    printf("%lld\n", dist[n-1]);
}