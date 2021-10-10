#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int A = 0;
    int B = 0;
    int best = 0;
    int curr = 0;
    while (A != n){
        if (a[A] < b[B])
            curr++, A++;
        else
            curr--, B++;
        best = max(best, curr);
    }
    cout << best << endl;
}