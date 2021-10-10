#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pairs;

bool isValid(int i, int j){
    if (pairs[i][1] == pairs[j][1] || pairs[i][1] == pairs[j][2]) return false;
    if (pairs[i][2] == pairs[j][1] || pairs[i][2] == pairs[j][2]) return false;
    return true;
}

int main(){
    int n, x; cin >> n >> x;
    if (n < 4) {cout << "IMPOSSIBLE" << endl; return 0;}
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    pairs.assign(n*(n-1)/2, {0, 0, 0});
    int count = 0;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            pairs[count][0] = p[i]+p[j], pairs[count][1] = i, pairs[count++][2] = j;
    sort(pairs.begin(), pairs.end());


    vector<int> res = {-1, -1, -1, -1};
    bool found = false;
    for (int i = 0; i < pairs.size()-1 && !found; i++){
        int target = x - pairs[i][0];
        int upper = count-1;
        int lower = i+1;
        while (upper != lower){
            int mid = (upper+lower)/2;
            if (pairs[mid][0] < target)
                lower = mid+1;
            else 
                upper = mid;
        }
        if (pairs[lower][0] != target) continue;
        while (lower < count && pairs[lower][0] == target){
            if (isValid(lower, i))
                {res[0] = pairs[lower][1], res[1] = pairs[lower][2], res[2] = pairs[i][1], res[3] = pairs[i][2]; found = true; break;}
            lower++;
        }
        lower--;
        while (lower >= 0 && pairs[lower][0] == target){
            if (isValid(lower, i))
                {res[0] = pairs[lower][1], res[1] = pairs[lower][2], res[2] = pairs[i][1], res[3] = pairs[i][2]; found = true; break;}
            lower--;
        }
    }
    if (res[0] != -1)
        cout << res[0]+1 << " " << res[1]+1 << " " << res[2]+1 << " " << res[3]+1 << endl;
    else 
        cout << "IMPOSSIBLE" << endl;
}