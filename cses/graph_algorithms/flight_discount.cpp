#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, int>

int n, m;
ll dist[100000], transD[100000];
vector<vector<ii>> graph, transG;

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<ii>());
    transG.assign(n, vector<ii>());
    while (m--){
        int a, b; ll c; scanf("%d %d %lld", &a, &b, &c); a--; b--;
        graph[a].push_back(ii(c, b));
        transG[b].push_back(ii(c, a));
    }
    memset(dist, -1, sizeof(dist));
    memset(transD, -1, sizeof(transD));
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, 0));
    while (!Q.empty()){
        ll d = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (dist[v] != -1) continue;
        dist[v] = d;
        for (int i = 0; i < graph[v].size(); i++)
            Q.push(ii(d+graph[v][i].first, graph[v][i].second));
    }

    Q.push(ii(0, n-1));
    while (!Q.empty()){
        ll d = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (transD[v] != -1) continue;
        transD[v] = d;
        for (int i = 0; i < transG[v].size(); i++)
            Q.push(ii(d+transG[v][i].first, transG[v][i].second));
    }
    ll result = (ll) 1e16;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < graph[i].size(); j++){
            ll path = dist[i] + graph[i][j].first / 2 + transD[graph[i][j].second];
            result = min(result, path);
        }
    }
    printf("%lld\n", result);
}