#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> color;

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<int>());
    while (m--){
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    color.assign(n, -1);
    queue<int> Q;
    bool isPos = true;
    for (int i = 0; i < n; i++){
        if (color[i] != -1) continue;
        color[i] = 1; Q.push(i);
        while (!Q.empty() && isPos){
            int v = Q.front();
            Q.pop();
            for (int i = 0; i < graph[v].size(); i++){
                int u = graph[v][i];
                if (color[u] == color[v])
                    isPos = false;
                if (color[u] == -1)
                    Q.push(u);
                color[u] = !color[v];
            }
        }
    }
    if (!isPos) {printf("IMPOSSIBLE\n"); return 0;}
    for (int i = 0; i < n; i++)
        printf("%d ", color[i]+1);
    printf("\n");
}