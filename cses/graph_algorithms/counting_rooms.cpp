#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m; char c;
int rooms[1001][1001];

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &c), rooms[i][j] = c == '#' ? -1 : 0;
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (rooms[i][j] != 0) continue;
            result++;
            queue<ii> Q; Q.push(ii(i, j));
            while (!Q.empty()){
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (rooms[x][y]) continue;
                rooms[x][y] = result;
                Q.push(ii(x-1, y));
                Q.push(ii(x+1, y));
                Q.push(ii(x, y-1));
                Q.push(ii(x, y+1));
            }
        }
    /*for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", (rooms[i][j] == -1 ? 0 : rooms[i][j]));
        printf("\n");
    }*/
    printf("%d\n", result);
}