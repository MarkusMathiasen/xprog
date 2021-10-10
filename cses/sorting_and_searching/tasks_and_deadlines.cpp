#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long

int main(){
    int n; cin >> n;
    vector<ii> task(n, ii(0, 0));
    for (int i = 0; i < n; i++)
        cin >> task[i].first >> task[i].second;
    sort(task.begin(), task.end());
    ll time = 0;
    ll result = 0;
    for (int i = 0; i < n; i++){
        int a = task[i].first;
        int d = task[i].second;
        time += a;
        result += d - time;
    }
    cout << result << endl;
}