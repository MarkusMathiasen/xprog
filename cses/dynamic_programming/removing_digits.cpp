#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; scanf("%d", &n);
    int result = 0;
    while (n > 0){
        int sub = 0;
        int cp = n;
        for (int i = 1; i < 7; i++)
            sub = max(sub, cp % 10), cp /= 10;
        n -= sub;
        result++;
    }
    printf("%d\n", result);
}