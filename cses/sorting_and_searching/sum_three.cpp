#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int n, x;
vector<ii> p;

int find(int from, int to, int target){
    while (from != to){
        int mid = (from+to) / 2;
        if (p[mid].first < target)
            from = mid+1;
        else 
            to = mid;
    }
    if (p[from].first == target)
        return from;
    else 
        return -1;
}

int main(){
    cin >> n >> x;
    p.assign(n, ii(0, 0));
    for (int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    int a1, a2, a3; a1 = a2 = a3 = -1;
    for (int i = 0; i < n-2; i++){
        for (int j = i+1; j < n-1; j++){
            int target = x - p[i].first - p[j].first;
            int ans = find(j+1, n-1, target);
            if (ans != -1)
                a1 = p[i].second, a2 = p[j].second, a3 = p[ans].second;
        }
    }
    if (a1 != -1)
        cout << a1+1 << " " << a2+1 << " " << a3+1 << endl;
    else 
        cout << "IMPOSSIBLE" << endl;
}