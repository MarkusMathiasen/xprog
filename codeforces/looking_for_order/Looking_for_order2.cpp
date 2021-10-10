#include <bits/stdc++.h>

using namespace std;

pair<int, int> start;
int objCount;
vector<pair<int, int>> objects;
vector<int> dp;
vector<pair<int, int>> parents;

int dist(int i, int j, int a, int b){
    int x = i - a;
    int y = j - b;
    return (x*x+y*y);
}

int bestWay(int state){
    if (dp[state] != -1) return dp[state];
    int result = 2000000000;
    pair<int, int> par(-1, -1);
    if (__builtin_popcount(state)+1 == objCount){
        int missing = -1;
        for (int i = 0; i < objCount; i++){
            if (state & (1 << i)) continue;
            missing = i;
            break;
        }
        parents[state].first = missing;
        parents[state].second = missing;
        return dp[state] = 2*dist(start.first, start.second, objects[missing].first, objects[missing].second);
    }
    for (int i = 0; i < objCount-1; i++){
        if (state & (1 << i)) continue;
        for (int j = i+1; j < objCount; j++){
            if (state & (1 << j)) continue;
            int travel = dist(start.first, start.second, objects[i].first, objects[i].second);
            travel += dist(objects[i].first, objects[i].second, objects[j].first, objects[j].second);
            travel += dist(start.first, start.second, objects[j].first, objects[j].second);
            int newState = (state | (1 << i));
            newState = (newState | (1 << j));
            int newDistance = travel + bestWay(newState);
            if (newDistance < result){
                result = newDistance;
                par.first = i; par.second = j;
            }
        }
    }
    parents[state].first = par.first;
    parents[state].second = par.second;
    return dp[state] = result;
}

int main(){
    cin >> start.first >> start.second;
    cin >> objCount;
    objects.assign(objCount, pair<int, int>(0, 0));
    for (int i = 0; i < objCount; i++)
        cin >> objects[i].first >> objects[i].second;
    int state = 0;
    dp.assign((1 << objCount), -1);
    parents.assign((1 << objCount), (make_pair(0, 0)));
    dp[(1 << objCount) -1] = 0;
    bestWay(state);
    cout << dp[0] << endl;
    while (state < (1 << objCount)-1){
        cout << 0 << " ";
        pair<int, int> par = parents[state];
        if (par.first != par.second)
            cout << par.first+1 << " " << par.second+1 << " ";
        else cout << par.first+1 << " ";
        state = (state | (1 << par.first));
        state = (state | (1 << par.second));
    }
    cout << 0 << endl;
}