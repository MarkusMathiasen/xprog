#include <bits/stdc++.h>
using namespace std;

vector<int> p, r;

void build(int N){
    p.assign(N+1, 0); r.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;           
}
int findSet(int i){
    return (p[i] == i ? i : p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j){return (findSet(i) == findSet(j));}

void unionSet(int i, int j){
    if (isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
    }
}

int main(){
    int N; cin >> N;
    string s;
    getline(cin, s); if (!cin.good()) return 0; getline(cin, s);
    for (; N > 0; N--){
        int size; cin >> size; getline(cin, s);
        build(size+1);
        int yes = 0, no = 0;
        while (getline(cin, s)){
            if (s.empty()) break;
            stringstream ss(s);
            char cmd; int c1, c2;
            ss >> cmd >> c1 >> c2;
            if (cmd == 'c') unionSet(c1, c2);
            else isSameSet(c1, c2) ? yes++ : no++;
        }
        cout << yes << ',' << no << endl; if (N > 1) cout << endl;
    }
}