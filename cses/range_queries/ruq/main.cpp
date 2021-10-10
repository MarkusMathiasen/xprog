#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, q;
ll lazy[800000];

int left(int i) {return i*2;}
int right(int i) {return i*2+1;};
void update(int i, int v, int l, int r, int L, int R){
	if (L > r || R < l) return;
	if (L >= l && R <= r) {lazy[i] += v; return;}
	int mid = (L+R)/2;
	update(left(i), v, l, r, L, mid);
	update(right(i), v, l, r, mid+1, R);
}
void update(int a, int b, int v) {return update(1, v, a, b, 1, n);}
ll getVal(int i, int p, int L, int R){
	if (L > p || R < p) return 0;
	if (L == R) {return lazy[i];}
	lazy[left(i)] += lazy[i];
	lazy[right(i)] += lazy[i];
	lazy[i] = 0;
	int mid = (L+R)/2;
	ll goL = getVal(left(i), p, L, mid);
	ll goR = getVal(right(i), p, mid+1, R);
	return goL+goR;
}
ll getVal(int p) {return getVal(1, p, 1, n);}

int main(){
	scanf("%d %d", &n, &q);
	
	for (int i = 1; i <= n; i++){
		int c; scanf("%d", &c);
		update(i, i, c);
	}
	while (q--){
		int o; scanf("%d", &o);
		if (o == 1){
			int a, b, v; scanf("%d %d %d", &a, &b, &v);
			update(a, b, v);
		}
		else{
			int p; scanf("%d", &p);
			printf("%lld\n", getVal(p));
		}
	}
}
