#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> tows(1, 0);
    cin >> tows[0];
    for (int i = 1; i < n; i++){
        int cube; cin >> cube;
        int upper = tows.size();
        int lower = 0;
        while (upper != lower){
            int mid = (upper+lower) / 2;
            if (tows[mid] > cube)
                upper = mid;
            else 
                lower = mid+1;
        }
        if (lower == tows.size())
            tows.push_back(cube);
        else 
            tows[lower] = cube;
    }
    cout << tows.size() << endl;
}