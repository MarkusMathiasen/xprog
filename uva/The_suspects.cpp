#include <bits/stdc++.h>
using namespace std;

vector<int> p, r, si;

void buildSets(int n) {
    p.assign(n, 0); r.assign(n, 0); si.assign(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
}
int findSet(int i)              {return p[i] == i ? i : p[i] = findSet(p[i]);}
bool isSameSet(int i, int j)    {return findSet(i) == findSet(j);}
int sizeOf(int i)               {return p[i] == i ? si[i] : sizeOf(p[i]);}

void unionSet(int i, int j){
    int x = findSet(i); int y = findSet(j);
    if (x == y) return; //If isSameSet(i, j)
    if (r[x] > r[y]) p[y] = x, si[x] += si[y];
    else {
        p[x] = y; si[y] += si[x];
        if (r[x] == r[y]) r[y]++;
    }
}

int main(){
    int n, groups; cin >> n >> groups;
    while (n){
        buildSets(n);
        for (int i = 0; i < groups; i++){
            int members, first; cin >> members >> first;
            while (--members > 0){
                int next; cin >> next;
                unionSet(first, next);
            }
        }
        cout << sizeOf(0) << endl;
        cin >> n >> groups;
    }
}