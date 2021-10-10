#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<ll, int>

int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<ll> partSums(n+1, 0);
    for (int i = 1; i <= n; i++)
        partSums[i] = partSums[i-1]+p[i-1];
    set<ii> s;
    ll result = partSums[a] - partSums[0];
    for (int i = a; i <= b; i++)
        s.insert(ii(partSums[i], i));
    for (int i = 0; s.size() > 0; i++){
        ll start = partSums[i];
        set<ii>::iterator it = s.end(); it--;
        result = max(result, (*it).first-start);
        if (i < n+1-a){
            s.erase(ii(partSums[i+a], i+a));
            if (i+b+1 <= n)
                s.insert(ii(partSums[i+b+1], i+b+1));
        }
    }
    cout << result << endl;
}