#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m, uf[100000], r[100000];

int find(int i){
    if (uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void merge(int i, int j){
    int x = find(i);
    int y = find(j);
    if (x == y) return;
    if (r[x] > r[y])
        {uf[y] = x; return;}
    uf[x] = y;
    if (r[x] == r[y]) r[y]++;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        uf[i] = i;
    while(m--){
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        merge(a, b);
    }
    vector<ii> results;
    for (int i = 1; i < n; i++){
        int x = find(0);
        int y = find(i);
        if (x != y){
            results.push_back(ii(x+1, y+1));
            merge(x, y);
        }
    }
    printf("%d\n", results.size());
    for (int i = 0; i < results.size(); i++)
        printf("%d %d\n", results[i].first, results[i].second);
}