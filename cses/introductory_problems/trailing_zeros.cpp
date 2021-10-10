#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n; int result = 0;
    for (long long div = 5; div <= n; div *= 5)
        result += n / div;
    cout << result << endl;
}