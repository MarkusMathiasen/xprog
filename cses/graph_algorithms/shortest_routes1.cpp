#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, int>

int n, m;
vector<vector<ii>> graph;
vector<ll> dist;

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<ii>());
    dist.assign(n, -1);
    while (m--) {
        int u, v, c; scanf("%d %d %d", &u, &v, &c); u--; v--;
        graph[u].push_back(ii(c, v));
    }
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
    for (int i = 0; i < n; i++)
        printf("%lld ", dist[i]);
    printf("\n");
}