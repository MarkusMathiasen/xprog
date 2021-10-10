#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii pair<int, ii>

int n, m;
vector<ii> monsters;
ii start;
int mt[1000][1000]; //monster time
char dir[1000][1000];
int dist[1000][1000];
ii last = {-1, -1};

void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", mt[i][j]);
        printf("\n");
    }       
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c; scanf(" %c", &c);
            if (c == '#') mt[i][j] = 0;
            if (c == '.') mt[i][j] = -1;
            if (c == 'M') mt[i][j] = -1, monsters.push_back(ii(i, j));
            if (c == 'A') mt[i][j] = -1, start.first = i, start.second = j;
        }
    queue<iii> Q;
    for (int i = 0; i < monsters.size(); i++)
        Q.push(iii(0, monsters[i]));
    while (!Q.empty()){
        int l = Q.front().first;
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        Q.pop();
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (mt[x][y] != -1) continue;
        mt[x][y] = l;
        Q.push(iii(l+1, ii(x+1, y)));
        Q.push(iii(l+1, ii(x-1, y)));
        Q.push(iii(l+1, ii(x, y+1)));
        Q.push(iii(l+1, ii(x, y-1)));
    }
    //print();
    queue<ii> q;
    q.push(start);
    memset(dist, -1, sizeof(dist));
    dist[start.first][start.second] = 0;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int l = dist[x][y];
        if (l >= mt[x][y] && mt[x][y] != -1) continue;
        if (x == 0 || x == n-1 || y == 0 || y == m-1){last=ii(x, y); break;}
        if (dist[x+1][y] == -1) {dist[x+1][y] = l+1; dir[x+1][y] = 'D'; q.push(ii(x+1, y));}
        if (dist[x-1][y] == -1) {dist[x-1][y] = l+1; dir[x-1][y] = 'U'; q.push(ii(x-1, y));}
        if (dist[x][y+1] == -1) {dist[x][y+1] = l+1; dir[x][y+1] = 'R'; q.push(ii(x, y+1));}
        if (dist[x][y-1] == -1) {dist[x][y-1] = l+1; dir[x][y-1] = 'L'; q.push(ii(x, y-1));}
    }
    if (last.first == -1) {printf("NO\n"); return 0;}
    printf("YES\n%d\n", dist[last.first][last.second]);
    vector<char> path;
    while (last != start){
        char c = dir[last.first][last.second];
        path.push_back(c);
        if (c == 'D') last.first--;
        if (c == 'U') last.first++;
        if (c == 'L') last.second++;
        if (c == 'R') last.second--;
    }
    for (int i = path.size()-1; i >= 0; i--)
        printf("%c", path[i]);
    printf("\n");
}