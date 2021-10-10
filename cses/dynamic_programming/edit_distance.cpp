#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
char s1[5000], s2[5000];
int dp[5000][5000];

int calcDist(int p1, int p2){
    if (p1 >= n || p2 >= m) return 1000000000;
    if (dp[p1][p2] != -1) return dp[p1][p2];
    int result = INT_MAX;
    if (s1[p1] == s2[p2]) return dp[p1][p2] = calcDist(p1+1, p2+1); //Nothing is needed to be done
    result = min(result, calcDist(p1+1, p2)+1); //insert new letter
    result = min(result, calcDist(p1+1, p2+1)+1); //switch letter
    result = min(result, calcDist(p1, p2+1)+1); //remove letter
    return dp[p1][p2] = result;
}

int main(){
    char c;
    scanf("%c", &c);
    while (c != '\n')
        s1[n] = c, n++, scanf("%c", &c);
    scanf("%c", &c);
    while (c != '\n')
        s2[m] = c, m++, scanf("%c", &c);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = -1;

    dp[n-1][m-1] = s1[n-1] == s2[m-1] ? 0 : 1;
    for (int i = m-2; i >= 0; i--)
        dp[n-1][i] = s1[n-1] == s2[i] ? m-i-1 : dp[n-1][i+1]+1;
    printf("%d\n", calcDist(0, 0));
}