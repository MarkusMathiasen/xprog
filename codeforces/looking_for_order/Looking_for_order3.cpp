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
    pair<int, int> par;
    
    int obj;
    for (int i = 0; i < objCount; i++){
        if (state & (1 << i)) continue;
        obj = i;
        break;
    }
    int travel = 2*dist(start.first, start.second, objects[obj].first, objects[obj].second);
    int newState = (state | (1 << obj));
    int newDistance = travel + bestWay(newState);
    if (newDistance < result){
        result = newDistance;
        par = make_pair(obj, obj);
    }

    for (int j = obj+1; j < objCount; j++){
        if (state & (1 << j)) continue;
        travel = dist(start.first, start.second, objects[obj].first, objects[obj].second);
        travel += dist(objects[obj].first, objects[obj].second, objects[j].first, objects[j].second);
        travel += dist(start.first, start.second, objects[j].first, objects[j].second);
        newState = (state | (1 << obj));
        newState = (newState | (1 << j));
        newDistance = travel + bestWay(newState);
        if (newDistance < result){
            result = newDistance;
            par.first = obj; par.second = j;
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