#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long

int n, k;
vector<int> p;
set<ii> s;
set<ii>::iterator med;
ll cost = 0;

void insert(ii x){
    s.insert(x);
    if (s.size() % 2 == 0){
        if (x < *med){
            int old = (*med).first;
            med--;
            cost += old - (*med).first;
        }
    }
    else if (x > *med)
        med++;
    cost += (x.first - (*med).first > 0 ? x.first - (*med).first : (*med).first - x.first);
}

void remove(ii x){
    if (s.size() % 2 == 0){
        if (x <= *med){
            cost -= (*med).first - x.first;
            int old = (*med).first;
            med++;
            int now = (*med).first;
            cost -= now - old;
        }
        else {
            cost -= x.first - (*med).first;
        }
    }
    else if (x >= *med){
        cost -= x.first - (*med).first;
        med--;
    }
    else 
        cost -= (*med).first - x.first;
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
    cout << cost;
    int R = k-1;
    int L = 0;
    while (R+1 < n){
        R++;
        insert(ii(p[R], R));
        remove(ii(p[L], L));
        L++;
        cout << " " << cost;
    }
    cout << endl;
}