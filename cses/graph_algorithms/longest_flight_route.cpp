#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> transG;
int dp[100000];
int p[100000];

int maxL(int v){
    if (dp[v] != -1) return dp[v];
    int result = -200000;
    for (int i = 0; i < transG[v].size(); i++)
        if (result < maxL(transG[v][i])+1){
            result = maxL(transG[v][i])+1;
            p[v] = transG[v][i];
        }
    return dp[v] = result;
}

int main(){
    memset(dp, -1, sizeof(dp));
    memset(p, -1, sizeof(p));
    dp[0] = 0;
    scanf("%d %d", &n, &m);
    transG.assign(n, vector<int>());
    while (m--){
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        transG[b].push_back(a);
    }
    int result = maxL(n-1);
    if (result < 0){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    printf("%d\n", result+1);
    vector<int> order(1, n-1);
    int pos = n-1;
    while (pos != 0){
        order.push_back(p[pos]);
        pos = p[pos];
    }
    for (int i = order.size()-1; i >= 0; i--)
        printf("%d ", order[i]+1);
    printf("\n");
}