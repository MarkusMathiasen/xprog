#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<vector<ll>> p;

int main(){
    scanf("%d", &n);
    p.assign(n, vector<ll>(3));
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &p[i][1], &p[i][0], &p[i][2]);
    sort(p.begin(), p.end());
    for (int i = 1; i < n; i++){
        int upper = i-1;
        int lower = 0;
        while (upper != lower){
            int mid = (upper+lower)/2;
            if (p[i][1] > p[mid][0])
                lower = mid+1;
            else 
                upper = mid;
        }
        if (p[i][1] > p[lower][0]) p[i][2] += p[lower][2];
        else if (lower) p[i][2] += p[lower-1][2];
        p[i][2] = max(p[i][2], p[i-1][2]);
    }
    printf("%lld\n", p[n-1][2]);
}