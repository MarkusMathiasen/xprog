#include <bits/stdc++.h>

using namespace std;

int startX, startY;
int O;
vector<int> objX, objY;
vector<int> dp;
vector<pair<int, int>> parrent;

int dist(int i, int j, int a, int b){
    int x = i - a;
    int y = j - b;
    return (x*x+y*y);
}

void calcTwoSteps(int state){
    for (int i = 0; i < O-1; i++){
        if (!(state & (1 << i))) continue;
        for (int j = i+1; j < O; j++){
            if (!(state & (1 << j))) continue;
            int newstate = (state & ~(1 << i));
            newstate = (newstate & ~(1 << j));
            int travel = dist(startX, startY, objX[i], objY[i]);
            travel += dist(objX[i], objY[i], objX[j], objY[j]);
            travel += dist(startX, startY, objX[j], objY[j]);
            if (dp[newstate] > travel+dp[state]){
                dp[newstate] = travel+dp[state];
                parrent[newstate] = make_pair(i, j);
            }
        }
    }
}

void printState(int n){
    for (int i = 4; i >= 0; i--)
        cout << ((n >> i) & 1);
    cout << endl;
}

void perms(int state, int L, int place){
    if (__builtin_popcount(state) == L){
        calcTwoSteps(state);
        return;
    }
    if (place == O) return;
    for (int i = place+1; i < O; i++){
        perms(state | (1 << i), L, i+1);
    }
}

int main(){
    cin >> startX >> startY;
    cin >> O;
    objX.assign(O, 0); objY.assign(O, 0);
    for (int i = 0; i < O; i++)
        cin >> objX[i] >> objY[i];
    int state = (1 << O) -1;
    dp.assign(state+1, 2000000000);
    parrent.assign(state+1, make_pair(0, 0));
    dp[state] = 0;
    
    for (int L = O; L > 1; L-=2)
        perms(state, L, 0);
    if (O % 2 == 1){
        int result = 2000000000;
        for (int i = 0; i < O; i++){
            int left = (1 << i);
            int distance = 2*dist(objX[i], objY[i], startX, startY);
            if (result > dp[left]+distance){
                result = dp[left]+distance;
                parrent[0] = make_pair(i, i);
            }
        }
        dp[0] = result;
    }
    cout << dp[0] << endl;
    int path = 0;
    while (path < state){
        cout << 0 << " ";
        pair<int, int> par = parrent[path];
        if (par.first != par.second) cout << par.first+1 << " " << par.second+1 << " ";
        else cout << par.first+1 << " ";
        path = (path | (1 << par.first));
        path = (path | (1 << par.second));
    }
    cout << 0 << endl;
}