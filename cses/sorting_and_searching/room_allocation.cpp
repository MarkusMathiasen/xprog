#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define iii pair<int, ii>

int main(){
    int n; cin >> n;
    vector<iii> cust(n, iii(0, ii(0, 0)));
    for (int i = 0; i < n; i++){
        cin >> cust[i].first >> cust[i].second.first;
        cust[i].second.second = i;
    }
    sort(cust.begin(), cust.end());
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(cust[0].second.first, 1));
    int result = 1;
    vector<int> room(n, 1);
    for (int i = 1; i < n; i++){
        int a = cust[i].first;
        int b = cust[i].second.first;
        int num = cust[i].second.second;
        if (a > Q.top().first){
            Q.push(ii(b, Q.top().second));
            room[num] = Q.top().second;
            Q.pop();
        }
        else {
            result++;
            Q.push(ii(b, result));
            room[num] = result;
        }
    }
    cout << result << endl;
    for (int i = 0; i < n; i++)
        cout << room[i] << " ";
    cout << endl;
}