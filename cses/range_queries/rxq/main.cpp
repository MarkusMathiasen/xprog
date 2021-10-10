#include <bits/stdc++.h>

using namespace std;

int n, q;
int p[200001], ps[200001];

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]), ps[i] = ps[i-1] ^ p[i];
	while (q--){
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", ps[b] ^ ps[a-1]);
	}
}
