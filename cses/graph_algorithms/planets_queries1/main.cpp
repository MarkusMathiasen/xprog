#include <bits/stdc++.h>

using namespace std;

int n, q;
int go[200000][31];

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &go[i][0]), go[i][0]--;
	for (int k = 1; k < 31; k++)
		for (int i = 0; i < n; i++)
			go[i][k] = go[go[i][k-1]][k-1];
	while (q--){
		int from, d; scanf("%d %d", &from, &d); from--;
		for (int i = 0; i < 31; i++)
			if (d & (1 << i))
				from = go[from][i];
		printf("%d\n", from+1);
	}
}
