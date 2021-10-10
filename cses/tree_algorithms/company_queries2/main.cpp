#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<int>> tree; //firsk k (2^K); next nodeNumber
vector<int> depth;
vector<bool> vis;

int goUp(int u, int h){
    for (int i = 19; i >= 0; i--)
        if (h & (1 << i))
            u = tree[i][u];
    return u;
}

int findDepth(int u){
    if(depth[u] != -1) return depth[u];
    return depth[u] = findDepth(tree[0][u])+1;
}

int main(){
    cin >> n >> q;
    tree.assign(19, vector<int>(n+1, 0));
    tree[0][1] = 1;
    for (int i = 2; i <= n; i++)
        cin >> tree[0][i];
    for (int k = 1; k < 19; k++)
        for (int u = 1; u <= n; u++)
            tree[k][u] = tree[k-1][tree[k-1][u]];
    
    depth.assign(n+1, -1);
    depth[1] = 0;
    for (int i = 2; i <= n; i++)
        findDepth(i);
    
    while (q--){
        int a, b; cin >> a >> b;
        if (depth[a] > depth[b])
            a = goUp(a, depth[a]-depth[b]);
        else 
            b = goUp(b, depth[b] - depth[a]);
        if (a == b) {
            cout << a << endl;
            continue;
        }
        int k = 18;
        while (k > -1){
            int aUp = tree[k][a];
            int bUp = tree[k][b];
            if (aUp == bUp)
                k--;
            else 
                a = aUp, b = bUp;
        }
        cout << tree[0][a] << endl;
    }
}