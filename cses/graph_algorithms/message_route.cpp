#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m;
vector<vector<int>> graph;
int p[100000];
int dist[100000];

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<int>());
    memset(p, -1, sizeof(p));
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < m; i++){
        int v1, v2; scanf("%d %d", &v1, &v2); v1--; v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    queue<int> Q;
    dist[0] = 1;
    p[0] = -2;
    Q.push(0);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < graph[v].size(); i++){
            int v2 = graph[v][i];
            if (p[v2] != -1) continue;
            p[v2] = v;
            dist[v2] = dist[v]+1;
            Q.push(v2);
        }
    }
    if (dist[n-1] == -1) {printf("IMPOSSIBLE"); return 0;}
    printf("%d\n", dist[n-1]);
    int path[dist[n-1]];
    int pos = n-1;
    for (int i = dist[n-1]-1; i >= 0; i--)
        path[i] = pos, pos = p[pos];
    for (int i = 0; i < dist[n-1]; i++)
        printf("%d ", path[i]+1);
    printf("\n");
}