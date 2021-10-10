#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int n, k;
vector<int> p;
set<ii> s;
set<ii>::iterator med;

void insert(ii x){
    s.insert(x);
    if (s.size() % 2 == 0){
        if (x < *med)
            med--;
    }
    else if (x > *med)
        med++;
}

void remove(ii x){
    if (s.size() % 2 == 0){
        if (x <= *med)
            med++;
    }
    else if (x >= *med)
            med--;
    s.erase(x);
}

int main(){
    cin >> n >> k;
    p.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    med = s.insert(ii(p[0], 0)).first;
    for (int i = 1; i < k; i++)
        insert(ii(p[i], i));
    int R = k-1;
    int L = 0;
    vector<int> result;
    result.push_back((*med).first);
    while (R+1 < n){
        R++;
        insert(ii(p[R], R));
        remove(ii(p[L], L));
        L++;
        result.push_back((*med).first);
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}