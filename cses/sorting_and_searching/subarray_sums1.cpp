#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    int result = 0;
    int l = 0;
    for (int i = 0; i < n; i++){
        sum += a[i]; l++;
        while (sum > x){
            sum -= a[i-l+1];
            l--;
        }
        if (sum == x) result++;
    }
    cout << result << endl;
}