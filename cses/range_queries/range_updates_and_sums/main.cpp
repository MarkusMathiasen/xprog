#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, q;
ll lazyAdd[800001], lazySet[800001], tree[800001];

int left(int i){return i*2;}
int right(int i){return i*2+1;}

ll put(int L, int R, int l, int r, int pos, int val){
	if (l > R || r < L) return tree[pos];
	if (l >= L && r <= R) {
		lazySet[pos] = val;
		lazyAdd[pos] = 0;
		return val*(r-l+1);
	}
	lazyAdd[left(pos)] = lazyAdd[pos];
	lazyAdd[right(pos)] = lazyAdd[pos];
	lazyAdd[pos] = 0;
	if (lazySet[pos]){
		lazySet[left(pos)] = lazySet[pos];
		lazySet[right(pos)] = lazySet[pos];
		lazySet[pos] = 0;
	}
	int mid = (l+r)/2;
	tree[pos] = 0;
	tree[pos] += put(L, R, l, mid, left(pos), val);
	tree[pos] += put(L, R, mid+1, r, right(pos), val);
	return tree[pos];
}
ll put(int L, int R, int val){return put(L, R, 1, n, 1, val);}
ll put(int pos, int val){return put(pos, pos, val);}
void add(int L, int R, int l, int r, int pos, int val){
	if (l > R || r < L) return;
	if (lazySet[pos]) {
		tree[pos] = lazySet[pos] * (r-l+1);
		lazySet[left(pos)] = lazySet[pos];
		lazySet[right(pos)] = lazySet[pos];
		lazySet[pos] = 0;
	}
	if (l >= L && r <= R) {lazyAdd[pos] += val; return;}
	lazyAdd[left(pos)] += lazyAdd[pos];
	lazyAdd[right(pos)] += lazyAdd[pos];
	lazyAdd[pos] = 0;
	int mid = (l+r)/2;
	add(L, R, l, mid, left(pos), val);
	add(L, R, mid+1, r, right(pos), val);
}
void add(int L, int R, int val){add(L, R, 1, n, 1, val);}
ll sum(int L, int R, int l, int r, int pos){
	if (l > R || r < L) return 0;
	if (lazySet[pos]){
		tree[pos] = lazySet[pos]*(r-l+1);
		lazySet[left(pos)] = lazySet[pos];
		lazySet[right(pos)] = lazySet[pos];
		lazySet[pos] = 0;
	}
	if (lazyAdd[pos]){
		lazyAdd[left(pos)] = lazyAdd[pos];
		lazyAdd[right(pos)] = lazyAdd[pos];
		tree[pos] += lazyAdd[pos];
		lazyAdd[pos] = 0;
	}
	if (l >= L && r <= R) return tree[pos];
	int mid = (l+r)/2;
	ll result = 0;
	result += sum(L, R, l, mid, left(pos));
	result += sum(L, R, mid+1, r, right(pos));
	return result;
}
ll sum(int L, int R){return sum(L, R, 1, n, 1);}

void print(){
	for (int i = 1; i <= n; i++)
		printf("%lld ", sum(i, i));
	printf("\n");
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		put(i, i, x);
	}
	print();
	while (q--){
		print();
		int o, a, b, x; scanf("%d %d %d", &o, &a, &b);
		if (o != 3) scanf("%d", &x);
		if (o == 1)
			add(a, b, x);
		else if (o == 2)
			put(a, b, x);
		else
			printf("%lld\n", sum(a, b));
	}
}
