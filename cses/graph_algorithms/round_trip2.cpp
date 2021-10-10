#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> result;
int vis[100000];
bool found = false;
int last = -1;
int visVal = 1;

bool dfs(int v){
    if (found) return true;
    if (vis[v] == -1) return false;
    if (vis[v] == visVal){
        result.push_back(v);
        last = v;
        return true;
    }
    if (vis[v]) return false;
    vis[v] = visVal;
    for (int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i];
        if (dfs(u)){
            if (found) return true;
            result.push_back(v);
            if (v == last) found = true;
            return true;
        }
    }
    vis[v] = -1;
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<int>());
    while (m--){
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        graph[a].push_back(b);
    }
    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        if (dfs(i)) break;
        visVal++;
    }
    if (result.size() == 0){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    printf("%d\n", result.size());
    for (int i = result.size()-1; i >= 0; i--)
        printf("%d ", result[i]+1);
    printf("\n");
}