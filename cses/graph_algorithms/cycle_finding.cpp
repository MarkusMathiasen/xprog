#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<int, int>

int n, m;
vector<vector<ii>> graph;
ll dist[2500];
vector<int> result;
vector<int> negStart; int pos = 0;
bool vis[2500];

bool findCyc(int v){
    if (v == negStart[pos]){
        if (vis[v] == true){
            result.push_back(v);
            return true;
        }
        else 
            vis[v] = true;
    }
    for (int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i].first; int d = graph[v][i].second;
        if (dist[u] > d+dist[v]){
            dist[u] = dist[v]+d;
            if (findCyc(u)){
                result.push_back(v);
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    graph.assign(n, vector<ii>());
    while (m--){
        int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
        graph[a].push_back(ii(b, c));
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < graph[i].size(); j++)
                dist[graph[i][j].first] = min(dist[graph[i][j].first], dist[i]+graph[i][j].second);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < graph[i].size(); j++){
            int u = graph[i][j].first; int d = graph[i][j].second;
            if (dist[u] > d+dist[i]){
                dist[u] = d+dist[i];
                negStart.push_back(u);
            }
        }
    if (negStart.size() == 0){
        printf("NO\n"); return 0;
    }
    bool found = false;
    while (!found){
        if (vis[negStart[pos]]) {pos++; continue;}
        found = findCyc(negStart[pos]);
    }
    printf("YES\n");
    for (int i = result.size()-1; i >= 0; i--)
        printf("%d ", result[i]+1);
    printf("\n");
}