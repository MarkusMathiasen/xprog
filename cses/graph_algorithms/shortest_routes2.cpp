#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, int>

int n, m, q; ll big = 1e12;
ll am[500][500];

int main(){
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            am[i][j] = i == j ? 0 : big;
    while (m--){
        int u, v; ll c; scanf("%d %d %lld", &u, &v, &c); u--; v--;
        am[u][v] = min(am[u][v], c);
        am[v][u] = min(am[v][u], c);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
    while (q--){
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        printf("%lld\n", (am[a][b] == big ? -1 : am[a][b]));
    }
}