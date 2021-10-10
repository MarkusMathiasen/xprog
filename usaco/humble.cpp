/*
ID: markus3
TASK: humble
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("humble.out");
ifstream fin ("humble.in");

#define ll long long
#define ii pair<ll, ll>

ll K, N;
vector<ll> S;
vector<priority_queue<ll, vector<ll>, greater<ll>>> q;

ll smallI(){
    ll bestI = -1;
    ll result = 1000000000000000000;
    for (ll i = 0; i < K; i++){
        if (q[i].empty()) continue;
        if (q[i].top() * S[i] < result){
            result = q[i].top() * S[i];
            bestI = i;
        }
    }
    return bestI;
}

int main() {
    fin >> K >> N;
    S.assign(K, 0);
    q.assign(K, priority_queue<ll, vector<ll>, greater<ll>>());
    for (ll i = 0; i < K; i++)
        fin >> S[i];
    q[0].push(1);
    while (--N){
        ll i = smallI();
        q[i].push(q[i].top()*S[i]);
        if (i+1 < K)
            q[i+1].push(q[i].top());
        q[i].pop();
    }
    ll i = smallI();
    fout << q[i].top() * S[i] << endl;
}
    