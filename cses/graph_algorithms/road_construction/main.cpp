#include <bits/stdc++.h>

using namespace std;

int n, m;
int compCount, bigComp = 1;
int uf[100000], r[100000];
int size[100000];

int find(int i){
	if (uf[i] == i) return i;
	return uf[i] = find(uf[i]);
}
void join(int i, int j){
	int x = find(i); int y = find(j);
	if (x == y) return;
	compCount--;
	if (r[x] > r[y]){
		uf[y] = x;
		size[x] += size[y];
		bigComp = max(bigComp, size[x]);
	}
	else {
		uf[x] = y;
		size[y] += size[x];
		bigComp = max(bigComp, size[y]);
		if (r[y] == r[x]) r[y]++;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	compCount = n;
	for (int i = 0; i < n; i++)
		uf[i] = i, size[i] = 1;
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		join(a, b);
		printf("%d %d\n", compCount, bigComp);
	}
}
