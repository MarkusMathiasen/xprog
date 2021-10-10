#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int main(){
    int n, x; cin >> n >> x;
    vector<ii> vals(n, ii(0, 0));
    for (int i = 0; i < n; i++){
        cin >> vals[i].first;
        vals[i].second = i;
    }
    sort(vals.begin(), vals.end());
    pair<int, int> result(-1, -1);
    for (int i = 0; i < n; i++){
        int v1 = vals[i].first;
        int target = x - v1;
        int upper = n-1;
        int lower = 0;
        while (lower != upper){
            int mid = (lower+upper) / 2;
            if (vals[mid].first < target)
                lower = mid+1;
            else 
                upper = mid;
        }
        if (lower == i){
            if (i < n-1 && vals[i+1] == vals[i])
                lower++;
            else if (i > 0 && vals[i-1] == vals[i])
                lower--;
            else 
                continue;
        }
        if (vals[i].first + vals[lower].first == x)
            result = {vals[i].second+1, vals[lower].second+1};
    }
    if (result.first == -1)
        cout << "IMPOSSIBLE" << endl;
    else 
        cout << result.first << " " << result.second << endl;
}
// Du skal gemme deres originale position, ved at lave hele arrayet om til pair. Det er lige meget når den sorterer, da den sorterer efter first først.