#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    int target = p[(n-1)/2];
    long long result = 0;
    for (int i = 0; i < n; i++){
        int diff = p[i] - target;
        if (diff < 0) diff = -diff;
        result += diff;
    }
    cout << result << endl;
}