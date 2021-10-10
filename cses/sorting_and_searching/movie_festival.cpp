#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int main(){
    int n; cin >> n;
    vector<ii> movies(n, ii(0, 0));
    for (int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
        swap(movies[i].first, movies[i].second);
    }
    sort(movies.begin(), movies.end());
    int last = movies[0].first;
    int result = 1;
    for (int i = 1; i < n; i++){
        int start = movies[i].second;
        int end = movies[i].first;
        if (start >= last)
            result++, last = end;
        last = min(last, end);
    }
    cout << result << endl;
}