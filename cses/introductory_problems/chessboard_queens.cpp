#include <bits/stdc++.h>

using namespace std;

char board[8][8];

bool isValid(int x, int y){
    if (board[x][y] == '*') return false;
    for (int i = 0; i < y; i++){
        int dist = y-i;
        if (x+dist < 8 && board[x+dist][i] == 'Q') return false;
        if (x-dist >= 0 && board[x-dist][i] == 'Q') return false;
        if (board[x][i] == 'Q') return false;
    }
    return true;
}

int dfs(int row){
    if (row == 8) return 1;
    int result = 0;
    for (int i = 0; i < 8; i++){
        if (isValid(i, row)){
            board[i][row] = 'Q';
            result += dfs(row+1);
            board[i][row] = '.';
        }
    }
    return result;
}

int main(){
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];
    cout << dfs(0) << endl;
}