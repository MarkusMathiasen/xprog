#include <bits/stdc++.h>
using namespace std;

vector<int> p, r;
vector<set<int>> enemies;

void buildSets(int n){
    p.assign(n, 0); r.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
    enemies.assign(n, set<int>());
}
int findSet(int i) {return p[i] == i ? i : p[i] = findSet(p[i]);}
bool isFriends(int i, int j) {return findSet(i) == findSet(j);}
bool isEnemies(int i, int j) {return enemies[findSet(i)].count(findSet(j));}

void beFriends(int i, int j){
    int x = findSet(i); int y = findSet(j);
    if (x == y) return;
    if (r[x] > r[y]) p[y] = x, enemies[x].insert(enemies[y].begin(), enemies[y].end());
    else {
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
        for (set<int>::iterator itx = enemies[x].begin(); itx != enemies[x].end(); itx++){
            for (set<int>::iterator ity = enemies[y].begin(); ity != enemies[y].end(); ity++)
                beFriends(*itx, *ity);
        }
        enemies[y].insert(enemies[x].begin(), enemies[x].end());
    }
}

void beEnemies(int i, int j){
    int x = findSet(i); int y = findSet(j);
    if (x == y) return;
    enemies[x].insert(y); enemies[y].insert(x);
    for (set<int>::iterator it = enemies[x].begin(); it != enemies[x].end(); it++)
        beFriends(*it, y);
    for (set<int>::iterator it = enemies[y].begin(); it != enemies[y].end(); it++)
        beFriends(*it, x);
}

int main(){
    int n; cin >> n;
    buildSets(n);
    int c, n1, n2; cin >> c >> n1 >> n2;
    while (c || n1 || n2){
        switch (c){
            case 1: //make friends
                if (isEnemies(n1, n2)) cout << -1 << endl;
                else beFriends(n1, n2);
                break;
            case 2: //make enemies
                if (isFriends(n1, n2)) cout << -1 << endl;
                beEnemies(n1, n2);
                break;
            case 3: //is friends?
                cout << isFriends(n1, n2) << endl;
                break;
            case 4: // is enemies?
                cout << isEnemies(n1, n2) << endl;
                break;
        }
        cin >> c >> n1 >> n2;
    }
}