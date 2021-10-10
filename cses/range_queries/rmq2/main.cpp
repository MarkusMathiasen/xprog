#include <bits/stdc++.h>

using namespace std;

int n, q;
int st[800000];

int left(int i) {return i*2;}
int right(int i) {return i*2+1;}
void update(int i, int t, int v, int L, int R){
	if (L > t || R < t) return;
	if (L == R) {st[i] = v; return;}
	int mid = (L+R)/2;
	update(left(i), t, v, L, mid);
	update(right(i), t, v, mid+1, R);
	st[i] = min(st[left(i)], st[right(i)]);
}
void update(int t, int v){update(1, t, v, 1, n);}
int rmq(int i, int l, int r, int L, int R){
	if (L > r || R < l) return INT_MAX;
	if (L >= l && R <= r) return st[i];
	int mid = (L+R)/2;
	int goL = rmq(left(i), l, r, L, mid);
	int goR = rmq(right(i), l, r, mid+1, R);
	return min(goL, goR);
}
int rmq(int l, int r) {return rmq(1, l, r, 1, n);}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		int c; scanf("%d", &c);
		update(i, c);
	}
	while (q--){
		int o, a, b; scanf("%d %d %d", &o, &a, &b);
		if (o == 1)
			update(a, b);
		else
			printf("%d\n", rmq(a, b));
	}
}
