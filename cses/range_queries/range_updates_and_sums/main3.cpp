#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, q;
ll st[800001], ladd[800001], lput[800001];

int left(int i) {return i*2;}
int right(int i) {return i*2+1;}

void flex(int p, int L, int R){
	if (L == R){
		if (lput[p]) st[p] = lput[p], lput[p] = 0;
		if (ladd[p]) st[p] += ladd[p], ladd[p] = 0;
		return;
	}
	if (lput[p]){
		st[p] = lput[p]*(R-L+1);
		lput[left(p)] = lput[p]; ladd[left(p)] = 0;
		lput[right(p)] = lput[p]; ladd[right(p)] = 0;
		lput[p] = 0;
	}
	if (ladd[p]){
		st[p] += ladd[p] * (R-L+1);
		ladd[left(p)] += ladd[p];
		ladd[right(p)] += ladd[p];
		ladd[p] = 0;
	}
}

void add(int L, int R, int l, int r, int p, int k){
	flex(p, L, R);
	if (L > r || R < l) return;
	if (L >= l && R <= r){
		ladd[p] += k;
		flex(p, L, R);
		return;
	}
	int mid = (L+R)/2;
	add(L, mid, l, r, left(p), k);
	add(mid+1, R, l, r, right(p), k);
	st[p] = st[left(p)] + st[right(p)];
}
void add(int l, int r, int k) {add(1, n, l, r, 1, k);}

void put(int L, int R, int l, int r, int p, int k){
	flex(p, L, R);
	if (L > r || R < l) return;
	if (L >= l && R <= r){
	       lput[p] = k;
	       flex(p, L, R);	       
	       return;
	}
	int mid = (L+R)/2;
	put(L, mid, l, r, left(p), k);
	put(mid+1, R, l, r, right(p), k);
	st[p] = st[left(p)] + st[right(p)];
}
void put(int l, int r, int k) {put(1, n, l, r, 1, k);}

ll sum(int L, int R, int l, int r, int p){
	flex(p, L, R);
	if (L > r || R < l) return 0;
	if (L >= l && R <= r)
		return st[p];
	int mid = (L+R)/2;
	ll lsum = sum(L, mid, l, r, left(p));
	ll rsum = sum(mid+1, R, l, r, right(p));
	return lsum+rsum;
}
ll sum(int l, int r) {return sum(1, n, l, r, 1);}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		put(i, i, x);
	}
	while (q--){
		int o, a, b, x; scanf("%d %d %d", &o, &a, &b);
		if (o == 3){
			printf("%lld\n", sum(a, b));
			continue;
		}
		scanf("%d", &x);
		if (o == 2)
			put(a, b, x);
		if (o == 1)
			add(a, b, x);
	}
}

