#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<int>> tree; //first is 2^k up second is startNode;

int main(){
    cin >> n >> q;
    tree.assign(19, vector<int>(n+1, 0));
    for (int i = 2; i <= n; i++)
        cin >> tree[0][i];
    for (int k = 1; k < 19; k++)
        for (int u = 2; u <= n; u++)
            tree[k][u] = tree[k-1][tree[k-1][u]];
    while (q--){
        int u, h; cin >> u >> h;
        for (int i = 19; i >= 0; i--){
            if (h & (1 << i)){
                u = tree[i][u];
            }
        }
        if (u == 0) cout << -1 << endl;
        else cout << u << endl;
    }
    
}