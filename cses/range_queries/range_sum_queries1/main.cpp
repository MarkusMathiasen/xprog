#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, q;
int a[200001];
ll sums[200001];

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sums[i] = sums[i-1]+a[i];
	while (q--){
		int a, b; scanf("%d %d", &a, &b);
		printf("%lld\n", sums[b]-sums[a-1]);
	}
}
