#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

struct state{
    int x;
    int y;
    int l;
    char op;
};

int n, m;
pair<int, char> lab[1000][1000];
pair<int, int> a, b;

void printLab(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (lab[i][j].first >= 0) printf(" ");
            printf("%d ", lab[i][j].first);
        }
            
        printf("\n");
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c; scanf(" %c", &c);
            if (c == '#') lab[i][j].first = -2;
            else lab[i][j].first = -1;
            if (c == 'A')
                a = ii(i, j);
            if (c == 'B')
                b = ii(i, j);
        }
    queue<state> Q;
    Q.push({a.first, a.second, 0, '0'});
    while (!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        int l = Q.front().l;
        char op = Q.front().op;
        Q.pop();
        if (x >= n || x < 0 || y >= m || y < 0) continue;
        if (lab[x][y].first != -1) continue;
        lab[x][y] = ii(l, op);
        //printLab();
        Q.push({x+1, y, l+1, 'D'});
        Q.push({x-1, y, l+1, 'U'});
        Q.push({x, y+1, l+1, 'R'});
        Q.push({x, y-1, l+1, 'L'});
    }
    if (lab[b.first][b.second].first == -1) {printf("NO\n"); return 0;}
    printf("YES\n");
    int x = b.first; int y = b.second;
    char ops[lab[b.first][b.second].first]; int pos = lab[b.first][b.second].first-1;
    while (x != a.first || y != a.second){
        ops[pos] = (lab[x][y].second);
        if (ops[pos] == 'D') x--;
        if (ops[pos] == 'U') x++;
        if (ops[pos] == 'L') y++;
        if (ops[pos] == 'R') y--;
        pos--;
    }
    printf("%d\n", lab[b.first][b.second].first);
    for (int i = 0; i < lab[b.first][b.second].first; i++)
        printf("%c", ops[i]);
    printf("\n");
}