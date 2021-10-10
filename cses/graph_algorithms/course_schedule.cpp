#include <bits/stdc++.h>

using namespace std;

int n, m;
bool isCom[100000];
vector<vector<int>> graph;
bool vis[100000];
vector<int> order;

bool complete(int v){
    if (isCom[v]) return true;
    if (vis[v]) return false;
    vis[v] = true;
    bool result = true;
    for (int i = 0; i < graph[v].size(); i++)
        if (!complete(graph[v][i]))
            result = false;
    if (result) order.push_back(v);
    return isCom[v] = result;
}

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<int>());
    while (m--){
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        graph[b].push_back(a);
    }
    bool possible = true;
    for (int i = 0; i < n; i++)
        if (!complete(i))
            possible = false;
    if (!possible){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (int i = 0; i < order.size(); i++)
        printf("%d ", order[i]+1);
    printf("\n");
}