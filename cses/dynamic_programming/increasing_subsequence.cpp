#include <bits/stdc++.h>

using namespace std;

int n, a[200000];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<int> s(1, a[0]);
    for (int i = 1; i < n; i++){
        if (s.back() < a[i]) {s.push_back(a[i]); continue;}
        int upper = s.size()-1;
        int lower = 0;
        while (upper != lower){
            int mid = (upper+lower)/2;
            if (s[mid] < a[i])
                lower = mid+1;
            else 
                upper = mid;
        }
        s[lower] = a[i];
    }
    printf("%d\n", s.size());
}