#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, q;
ll st[800001];
vector<int> lazy[800001];

int left(int i) {return i*2;}
int right(int i) {return i*2+1;}

void norm(int L, int R, int p, int t, int k){
	if (L > t || R < t) return;
	st[p] += k;
	if (L == t && R == t) return;
	int mid = (L+R)/2;
	norm(L, mid, left(p), t, k);
	norm(mid+1, R, right(p), t, k);
}
void norm(int t, int k) {norm(1, n, 1, t, k);}

void flex(int p, int L, int R, int l){
	if (!lazy[p].size()) return;
	if (L == R){
		for (int i : lazy[p])
			st[p] += i;
		lazy[p].resize(0);
		return;
	}
	int mid = (L+R)/2;
	for (int i : lazy[p]){
		lazy[left(p)].push_back(i);
		if (i+mid-l+1 > 0)
			lazy[right(p)].push_back(i+mid-l+1);
	}
	lazy[p].resize(0);
	ll s = R-L+1;
	st[p] += (s*s+s)/2;
}

void update(int L, int R, int l, int r, int p, int k){
	flex(p, L, R, l);
	if (L > r || R < l) return;
	if (L >= l && R <= r){
		lazy[p].push_back(k);
		flex(p, L, R, l);
		return;
	}
	int mid = (L+R)/2;
	update(L, mid, l, r, left(p), k);
	update(mid+1, R, l, r, right(p), k+mid-l+1);
	st[p] = st[left(p)] + st[right(p)];
}
void update(int l, int r) {update(1, n, l, r, 1, 1);}

ll sum(int L, int R, int l, int r, int p){
	flex(p, L, R, l);
	if (L > r || R < l) return 0;
	if (L >= l && R <= r) return st[p];
	int mid = (L+R)/2;
	ll lsum = sum(L, mid, l, r, left(p));
	ll rsum = sum(mid+1, R, l, r, right(p));
	return lsum+rsum;
}
ll sum(int l, int r) {return sum(1, n, l, r, 1);}

void print(){
	for (int i = 1; i <= n; i++)
		printf("%lld ", sum(i, i));
	printf("\n");
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		norm(i, x);
	}
	while (q--){
		int o, a, b; scanf("%d %d %d", &o, &a, &b);
		printf("%d %d\n", a, b);
		if (o == 1)
			update(a, b);
		else
			printf("%lld\n", sum(a, b));
		print();
	}
}
