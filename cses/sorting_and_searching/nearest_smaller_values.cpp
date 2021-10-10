#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int main(){
    int n; cin >> n;
    vector<ii> p(1, ii(0, 0)); cin >> p[0].first; cout << 0;
    for (int i = 1; i < n; i++){
        int c; cin >> c;
        int lower = 0;
        int upper = p.size()-1;
        while (lower < upper){
            int mid = (upper+lower)/2;
            if (p[mid].first >= c)
                upper = mid-1;
            else 
                lower = mid;
            if (lower +1 == upper){
                if (p[upper].first < c)
                    lower++;
                else 
                    upper--;
            }
        }
        if (p[lower].first < c) cout << " " << p[lower].second+1;
        else cout << " " << 0;
        while (p.size() > 0 && c <= p.back().first)
            p.pop_back();
        p.push_back(ii(c, i));
    }
    cout << endl;
}