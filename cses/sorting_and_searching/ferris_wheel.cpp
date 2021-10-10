#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    int L = 0;
    int R = n-1;
    int result = 0;
    while (L < R){
        result++;
        int sum = p[L]+p[R];
        if (sum <= x)
            L++;
        R--;
    }
    if (L == R)
        result++;
    cout << result << endl;
}