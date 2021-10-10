#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> p;
vector<int> path;
bool found = false;


bool dfs(int v){
    for (int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i];
        if (u == p[v]) continue;
        if (p[u] != -1){
            path.push_back(u);
            path.push_back(v);
            return true;
        }
        p[u] = v;
        if (dfs(u)){
            path.push_back(v);
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<int>());
    while (m--){
        int v, u; scanf("%d %d", &v, &u); v--; u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    p.assign(n, -1);
    for (int i = 0; i < n && !found; i++)
        if (p[i] == -1)
            found = dfs(i);
    if (!found) {printf("IMPOSSIBLE\n"); return 0;}
    int count = 2;
    while (path[count] != path[0]) count++;
    printf("%d\n", count+1);
    printf("%d %d", path[0]+1, path[1]+1);
    for (int i = 2; path[i-1] != path[0]; i++)
        printf(" %d", path[i]+1);
    printf("\n");    
}