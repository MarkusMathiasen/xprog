#include <bits/stdc++.h>

using namespace std;

int n, m;
int st[800000];

int left(int i) {return i*2;}
int right(int i) {return i*2+1;}
void update(int i, int p, int k, int L, int R){
	if (L > p || R < p) return;
	if (L == R) {st[i] += k; return;}
	int mid = (L+R)/2;
	update(left(i), p, k, L, mid);
	update(right(i), p, k, mid+1, R);
	st[i] = max(st[left(i)], st[right(i)]);
}
void update(int p, int k) {return update(1, p, k, 1, n);}
int find(int i, int v, int L, int R){
	if (L == R) return L;
	int mid = (L+R)/2;
	if (st[left(i)] >= v) return find(left(i), v, L, mid);
	return find(right(i), v, mid+1, R);
}
int find(int v) {return find(1, v, 1, n);}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		int k; scanf("%d", &k);
		update(i, k);
	}
	while (m--){
		int k; scanf("%d", &k);
		if (st[1] < k)
			{printf("0 "); continue;}
		int pos = find(k);
		printf("%d ", pos);
		update(pos, -k);
	}
	printf("\n");
}
