#include <bits/stdc++.h>

using namespace std;

int n;
int coins[100];
bool isValid[1000001];
set<int> s;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    sort(coins, coins+n);
    isValid[0] = true;
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 999999; j >= 0; j--)
            if (isValid[j] && !isValid[j+coins[i]])
                isValid[j+coins[i]] = true, result++;
        
    printf("%d\n", result);
    for (int i = 1; i <= 1000000; i++)
        if (isValid[i])
            printf("%d ", i);
    printf("\n");
}