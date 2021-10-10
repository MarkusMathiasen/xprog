#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int main(){
    int n, k; cin >> n >> k;
    vector<ii> movies(n, ii(0, 0));
    for (int i = 0; i < n; i++)
        cin >> movies[i].second >> movies[i].first;
    sort(movies.begin(), movies.end());
    set<ii> s;
    for (int i = 0; i < k; i++)
        s.insert(ii(0, i));
    int result = 0;
    for (int i = 0; i < n; i++){
        int start = movies[i].second;
        int end = movies[i].first;
        set<ii>::iterator person = s.lower_bound(ii(-start, 0));
        if (person == s.end()) continue;
        result++;
        s.insert(ii(-end, (*person).second));
        s.erase(*person);
    }
    cout << result << endl;
}