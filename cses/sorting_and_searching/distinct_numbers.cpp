#include <bits/stdc++.h>

using namespace std;

set<int> vals;

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int v; cin >> v;
        if (vals.count(v)) continue;
        vals.insert(v);
    }
    cout << vals.size() << endl;
}