#include <bits/stdc++.h>

using namespace std;

char ops[48];
bool vis[7][7];

int dfs(int x, int y, int count){
    if (x < 0 || y < 0 || x > 6 || y > 6) return 0;
    if (vis[x][y]) return 0;
    if (x == 0 && y == 6){
        if (count == 48)    return 1;
        else                return 0;
    }
    vis[x][y] = true;
    int result = 0;
    if (ops[count] != '?'){
        if (ops[count] == 'R') result = dfs(x+1, y, count+1);
        else if (ops[count] == 'L') result = dfs(x-1, y, count+1);
        else if (ops[count] == 'U') result = dfs(x, y-1, count+1);
        else result = dfs(x, y+1, count+1);
    }
    else{
        result += dfs(x+1, y, count+1);
        result += dfs(x-1, y, count+1);
        result += dfs(x, y-1, count+1);
        result += dfs(x, y+1, count+1);
    }
    vis[x][y] = false;
    return result;
}

int main(){
    for (int i = 0; i < 48; i++)
        cin >> ops[i];
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            vis[i][j] = false;
    cout << dfs(0, 0, 0);
}