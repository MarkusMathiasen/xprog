#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> des(n, 0);
    vector<int> app(m, 0);
    for (int i = 0; i < n; i++)
        cin >> des[i];
    for (int i = 0; i < m; i++)
        cin >> app[i];
    sort(des.begin(), des.end());
    sort(app.begin(), app.end());
    int d = 0; int a = 0;
    int result = 0;
    while (d < n && a < m){
        int diff = des[d] - app[a];
        if (diff < 0) diff = -diff;
        if (diff <= k){
            result++;
            d++, a++;
            continue;
        }
        if (des[d] < app[a])
            d++;
        else 
            a++;
    }
    cout << result << endl;
}