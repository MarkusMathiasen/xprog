#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, p[5000], partSums[5001];
ll dp[5000][5000];

ll calcPoints(int x, int y){
    if (dp[x][y] != -1) return dp[x][y];
    ll result = partSums[y+1]-partSums[x] - calcPoints(x+1, y);//Take first
    result = max(result, partSums[y+1]-partSums[x] - calcPoints(x, y-1)); //Take last
    return dp[x][y] = result;
}

int main(){
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    for (int i = 0; i < n; i++)
        scanf("%lld", &p[i]), partSums[i+1] = partSums[i]+p[i];
    for (int i = 0; i < n; i++)
        for (int j = i; j < i+2 && j < n; j++)
            dp[i][j] = max(p[i], p[j]);
    ll result = calcPoints(0, n-1);
    printf("%lld\n", result);    
}