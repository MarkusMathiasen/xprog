#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, int>

int n, m, k;
vector<vector<ii>> graph;
vector<ll> result;
int visCount[200000];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    graph.assign(n, vector<ii>());
    while (m--){
        int a, b; ll c; scanf("%d %d %lld", &a, &b, &c); a--; b--;
        graph[a].push_back(ii(c, b));
    }
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, 0));
    while (!Q.empty() && result.size() < k){
        ll d = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (visCount[v] >= k) continue;
        visCount[v]++;
        if (v == n-1) result.push_back(d);
        for (int i = 0; i < graph[v].size(); i++)
            Q.push(ii(d+graph[v][i].first, graph[v][i].second));
    }
    for (int i = 0; i < result.size(); i++)
        printf("%lld ", result[i]);
    printf("\n");
}